%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "TS_fct.h"
    
    extern int nb_ligne;
    extern int col;
    extern int yylex();
    extern char* yytext;
    int yyerror(const char *s);
    
    // Compteur d'erreurs
    int nb_erreurs = 0;
%}

%union {
    int entier;
    float reel;
    char* str;

}

/* Declaration des tokens */
%token MAINPRGM VAR BEGINPG ENDPG
%token LET DEFINE CONST INT FLOAT
%token <str> IDF
%type <str> var_list type
%token <entier> CST_INT
%token <reel> CST_FLOAT
%token IF THEN ELSE DO WHILE FOR FROM TO STEP
%token INPUT OUTPUT
%token ASSIGN AND OR
%token GT LT GE LE EQ NE



/* Priorites des operateurs */
%left OR
%left AND
%left '!'
%left GT LT GE LE EQ NE
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

/* Definition de la structure globale du programme */
programme : MAINPRGM IDF ';' VAR declarations BEGINPG '{' instructions '}' ENDPG ';'
          {  
              inserer($2,"motCle","null", "false");
              if (nb_erreurs == 0) {
                  printf("\nProgramme valide !\n");
              } else {
                  printf("\nProgramme invalide. %d erreur(s) detectee(s).\n", nb_erreurs);
              }
          }
          | error 
          {
              yyerror("Erreur dans la structure globale du programme");
              yyerrok;
          }
          ;

/* Declarations de variables et constantes */
declarations : declaration declarations
             | declaration
             | /* vide */
             ;

declaration : var_decl
            | const_decl
            | error ';'
            {
                yyerror("Erreur dans la declaration");
                yyerrok;
            }
            ;

/* Declaration des variables */
var_decl : LET var_list ':' type ';'
         {
                  int i = 0;
                  char *token = strtok($2, ",");
                  char buffer[100];
                  while (token != NULL) {
                    int inserted = inserer(token,"Idf","null", "false");
                    if(inserted == -1){
                        snprintf(buffer, sizeof(buffer), "Erreur: double declaraion de l'entite %s\n", token);
                        yyerrorSemantique(buffer);
                        yyerrok;
                    }
                    else if(inserted != 0){
                          i= update(token, $4, "false","null",1);
                          printf("\nDeclaration de variables %s de type %s\n",token,$4);
                    }
                       token = strtok(NULL, ",");
                    } 
         }
         | LET var_list ':' '[' type ';' CST_INT ']' ';'
         {         char buffer[100];
                   char *token = strtok($2,",");
                   while (token != NULL) {
                      int inserted = inserer(token,"Idf","null","false");
                      if(inserted == -1){
                           
                          snprintf(buffer, sizeof(buffer), "Erreur: double delaration de l'entite %s\n", token);
                          yyerrorSemantique(buffer);
                          yyerrok;
                      }else if(inserted != 0){
                       if($7 <= 0){
                         snprintf(buffer, sizeof(buffer), "Erreur: La taille du tableau %s doit etre positive\n", token);
                         yyerror(buffer);
                         yyerrok;
                        }else{
                            int i= update(token, $5, "false","null",$7);   
                              switch (i) {
                         case -1: 
                             snprintf(buffer, sizeof(buffer), "Erreur: Le tableau %s n'est pas declare\n", token);
                             yyerror(buffer);
                             yyerrok;
                             break;
                         default:
                             printf("\nDeclaration de tableau %s de type %s [%d]\n", $2, $5, $7);
                             break;
                                          } 
                              }}
                     token = strtok(NULL, ",");
                    } 
            }  
         /* Gestion des erreurs */
         | LET var_list ':' '[' type error ';'
         { 
             yyerror("Erreur: Mauvaise declaration du tableau. Syntaxe attendue: [type;taille] \n");
             yyerrok;
         }
         | LET var_list ':' error ';'
         { 
             yyerror("Erreur: Type invalide dans la declaration de variable \n");
             yyerrok;
         }
         | LET error ':' type ';'
         {
             yyerror("l'une des varialbles est mal declares\n");
             yyerrok;
         };
         | LET error ':' '[' type ';' CST_INT ']' ';'
         {
             yyerror("l'un des array est mal declares est mal declares\n");
             yyerrok;
         };

/* Liste des variables */
var_list : IDF ',' var_list {
    char* buffer = malloc(strlen($1) + strlen($3) + 2);
    sprintf(buffer, "%s,%s", $1, $3);
    $$ = buffer;

}
| IDF {
    $$ = strdup($1);  // Copie du nom
}
| error {

    $$ = strdup("???");
};


/* Declaration de constantes */
const_decl : DEFINE CONST IDF ':' type '=' CST_INT ';'
           { 
              char value_str[12],buffer[100];
              int inserted= inserer($3,"Idf","null", "false");
              if(inserted == -1){
                  yyerrorSemantique(buffer,"\nErreur: double delaration de l'entite %s\n", $3);
                  yyerror(buffer);
                  yyerrok;
                  return;
              }
             
                snprintf(value_str, sizeof(value_str), "%d", $7);
                 int i= update($3,"Int","true",value_str,1);
                if(i == -1){
                    sprintf(buffer, "\nErreur dans la declaration de constante %s \n", $3);
                    yyerror(buffer);
                    yyerrok;
                }else{
                    printf("\nDeclaration de constante entiere %s = %d\n ",$3,$7);
                  }
            }
           | DEFINE CONST IDF ':' type '=' CST_FLOAT ';'
           { 

              char value_str[12],buffer[100];
              int inserted= inserer($3,"Idf","null", "false");
                if(inserted == -1){
                    yyerrorSemantique("\nErreur: double delaration de l'entite %s\n", $3);
                    yyerrok;
                    return;
                }
                snprintf(value_str, sizeof(value_str), "%f", $7);
                 int i= update($3,"Float","true",value_str,1);
                if(i == -1){
                    sprintf(buffer,"\nErreur dans la declaration de constante %s \n", $3);
                    yyerror(buffer);
                    yyerrok;
                }else{
                    printf("\nDeclaration de constante flottante %s = %f\n ",$3,$7);
                }
              
            }
           |DEFINE CONST IDF ':' type '=' error ';'
           { 
               yyerror("Erreur: Valeur de constante doit etre un iniger ou float");
               yyerrok;
           } 
           | DEFINE error
           {
               yyerror("Erreur dans la declaration de constante");
               yyerrok;
           }
           ;

/* Types */
type : INT {
    $$ = strdup("Int");
}
| FLOAT {
    $$ = strdup("Float");
}
| error  {
    yyerror("Type non reconnu");
    yyerrok;
    $$ = strdup("Unknown");
};


/* Instructions */
instructions : instruction instructions
             | instruction
             | /* vide */
             ;

instruction : affectation
            | condition
            | boucle_do
            | boucle_for
            | lecture
            | ecriture
            | error ';'
            {
                yyerror("Erreur dans l'instruction");
                yyerrok;
            }
            ;

affectation : IDF ASSIGN expression ';'
            { 
                char buffer[100];
                int i = recherche($1);

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", $1);
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // appedend a value to a const
                } else  {
                    int isConstante = isConst($1);  
                    if(isConstante == 1) {
                        snprintf(buffer,sizeof(buffer),"Erreur: La constante %s ne peut pas etre modifiee\n", $1);
                        yyerrorSemantique(buffer);
                        yyerrok;

                        // no problem
                    } else {
                        printf("Affectation pour entite %s \n",$1);
                    }
                } 
                
             }
            |IDF '=' expression ';' {
                  char buffer[100];
                  snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
                  yyerror(buffer);
                  yyerrok;
            } 
            | IDF '[' CST_INT ']' ASSIGN expression ';'
            { 
               char buffer[100];
               int i = recherche($1);
               int erreur = 0;

               if (i == -1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas declaree\n", $1);
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else if (ts[i].Length == 1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas un tableau\n", $1);
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else {
                   int index = $3;
                   if (index < 0 || index >= ts[i].Length) {
                       snprintf(buffer, sizeof(buffer), "Erreur: L'indice %d est hors limites pour le tableau %s\n", index, $1);
                       yyerrorSemantique(buffer);
                       erreur = 1;
                   }
               }

               if (!erreur) {
                   printf("\nAffectation pour tableau %s[%d] \n", $1, $3);
               }
            }
            | IDF '[' CST_INT ']' '=' expression ';' {
                char buffer[100];
                snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
                yyerror(buffer);
                yyerrok;
            }
            | IDF ASSIGN expression error
            { 
                yyerror("Erreur: Point-virgule manquant apres l'affectation");
                yyerrok;
            }
            | IDF '[' CST_INT ']' ASSIGN expression error
            {
                yyerror("Erreur: Point-virgule manquant apres l'affectation de tableau");
                yyerrok;
            }
            | error ASSIGN CST_INT ';'
            {
                yyerror("Erreur: Identificateur invalide dans l'affectation");
                yyerrok;
            }
            ;

condition : IF '(' expression ')' THEN '{' instructions '}'
          { printf("\nCondition if sans else\n"); }
          | IF '(' expression ')' THEN '{' instructions '}' ELSE '{' instructions '}'
          { printf("\nCondition if-else\n"); }
          | IF '(' error ')' THEN '{' instructions '}'
          {
              yyerror("Erreur dans la condition du if");
              yyerrok;
          }
          | IF error 
          {
              yyerror("Erreur: Syntaxe incorrecte pour la condition if -if error");
              yyerrok;
          }
          | error 
          {
              yyerror("Erreur: Syntaxe incorrecte pour la condition if -error");
              yyerrok;
          }
          ;

boucle_do : DO '{' instructions '}' WHILE '(' expression ')' ';'
          { printf("\nBoucle do-while\n"); }
          | DO '{' instructions '}' WHILE error ';'
          {
              yyerror("Erreur: Parentheses manquantes autour de la condition while");
              yyerrok;
          }
          | DO error
          {
              yyerror("Erreur: Syntaxe incorrecte pour la boucle do-while");
              yyerrok;
          }
          ;

boucle_for : FOR IDF FROM expression TO expression STEP expression '{' instructions '}'
           { 
                char buffer[100];
                int i = recherche($2);

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", $2);
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // no problem
                } else  {
                        printf("\nboucle for bien forme \n");
                } 

            }
           | FOR error
           {
               yyerror("Erreur: Syntaxe incorrecte pour la boucle for");
               yyerrok;
           }
           ;

lecture : INPUT '(' IDF ')' ';'
        { 
                char buffer[100];
                int i = recherche($3);

                // undeclared variable
                if(i == -1) {
                    snprintf(buffer,sizeof(buffer),"Erreur: entite %s n'est pas declaree\n", $3);
                    yyerrorSemantique(buffer);
                    yyerrok;

                    // appedend a value to a const
                } else  {
                    printf("Instruction input pour entite %s \n",$3);
                } 

         }
        | INPUT '(' error ')' ';'
        {
            yyerror("Erreur: Identificateur invalide dans l'instruction input");
            yyerrok;
        }
        | INPUT error
        {
            yyerror("Erreur: Syntaxe incorrecte pour l'instruction input");
            yyerrok;
        }
        ;

ecriture : OUTPUT '(' expression_liste ')' ';'
         { 
                printf("\nInstruction output appele \n");
         } 
         | OUTPUT error
         {
             yyerror("Erreur: Syntaxe incorrecte pour l'instruction output");
             yyerrok;
         }
         ;

expression_liste : expression ',' expression_liste
                 | expression
                 | error
                 {
                     yyerror("Erreur dans la liste d'expressions");
                     yyerrok;
                 }
                 ;

expression : expression '+' expression
           | expression '-' expression
           | expression '*' expression
           | expression '/' expression
           | '(' expression ')'
           | expression AND expression
           | expression OR expression
           | '!' expression
           | expression GT expression
           | expression LT expression
           | expression GE expression
           | expression LE expression
           | expression EQ expression
           | expression '=' expression {
              char buffer[100];
              snprintf(buffer,sizeof(buffer),"Erreur: L'operateur '=' est une affectation, pas une comparaison\n");
              yyerror(buffer);
                yyerrok;
           }
           | expression NE expression
           | IDF  {
                char buffer[100];
                int i = recherche($1);
    
                // undeclared variable
                if(i == -1) {
                     snprintf(buffer,sizeof(buffer),"Erreur: La variable %s n'est pas declaree\n", $1);
                     yyerrorSemantique(buffer);
                     yyerrok;
    
                     // appedend a value to a const
                } else  {
                     printf("\nExpression pour entite %s \n",$1);
                }
           }
           | IDF '[' CST_INT ']'
              {
                char buffer[100];
                 int i = recherche($1);
                 int erreur = 0;

               if (i == -1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas declaree\n", $1);
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else if (ts[i].Length == 1) {
                   snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas un tableau\n", $1);
                   yyerrorSemantique(buffer);
                   erreur = 1;
               } else {
                   int index = $3;
                   if (index < 0 || index >= ts[i].Length) {
                       snprintf(buffer, sizeof(buffer), "Erreur: L'indice %d est hors limites pour le tableau %s\n", index, $1);
                       yyerrorSemantique(buffer);
                       erreur = 1;
                   }
               }

               if (!erreur) {
                   printf("\nAffectation pour tableau %s[%d] \n", $1, $3);
               }
              }
           | CST_INT
           | CST_FLOAT
           | error 
           {
              yyerror("Erreur dans l'expression");
              yyerrok;
         
           }
           ;

%%

/* Fonction d'affichage des erreurs */
int yyerror(const char *s) {
    printf("\nErreur Syntaxique a la ligne %d, colonne %d: %s\n", nb_ligne, col, s);
    nb_erreurs++;
    return 0;
}

int yyerrorSemantique(const char *s) {
    printf("\nErreur semantique a la ligne %d, colonne %d: %s\n", nb_ligne, col, s);
    nb_erreurs++;
    return 0;
}


int main() {
    printf("Analyse syntaxique...\n");
    yyparse();  
    afficher();
    return 0;
}