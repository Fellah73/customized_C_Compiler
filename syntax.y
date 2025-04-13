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

    // Structure pour stocker les informations d'une expression
    typedef struct {
        int value;
        char *name;  // Pour les variables
        int is_var;  // 1 si c'est une variable, 0 sinon
        char *type;  // tracking du type
    } ExprInfo;

%}

%union {
    int entier;
    float reel;
    char* str;
    char* type;  // Ajout d'un champ pour le type
    struct {
        int value;
        char *name;  // Pour les variables
        int is_var;  // 1 si c'est une variable, 0 sinon
        char *type;  // tracking du type
    } expr_info;

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
%type <expr_info> expression



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
            char *token = strtok(strdup($2), ",");  // Utilisez strdup pour éviter de modifier $2
            char buffer[100];
            while (token != NULL) {
                int i = recherche(token);
                if (i != -1) {
                    // Variable déjà déclarée
                    snprintf(buffer, sizeof(buffer), "Double declaration de la variable %s", token);
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    int inserted = inserer(token, "Idf", "null", "false");
                    i = update(token, $4, "false", "null", 1);
                    printf("Declaration de variables %s de type %s\n", token, $4);
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
            yyerror("Erreur dans la liste des variables\n");
            yyerrok;
            $$ = strdup("???");
        };

/* Declaration de constantes */
const_decl : DEFINE CONST IDF ':' type '=' CST_INT ';'
           { 
               char value_str[12], buffer[100];
                int inserted = inserer($3, "Idf", "null", "false");
                if(inserted == -1) {
                    snprintf(buffer, sizeof(buffer), "Double declaration de l'entite %s", $3);
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    // Vérification de la compatibilité de type
                    if (strcmp($5, "Int") != 0 && strcmp($5, "Float") != 0) {
                        snprintf(buffer, sizeof(buffer), "Type %s incompatible pour la constante %s", $5, $3);
                        yyerrorSemantique(buffer);
                        yyerrok;
                    } else {
                        snprintf(value_str, sizeof(value_str), "%d", $7);
                        int i = update($3, $5, "true", value_str, 1);
                        if(i == -1) {
                            snprintf(buffer, sizeof(buffer), "Erreur dans la declaration de constante %s", $3);
                            yyerror(buffer);
                            yyerrok;
                        } else {
                            printf("Declaration de constante entiere %s = %d\n", $3, $7);
                        }
                    }
                }
            }
           | DEFINE CONST IDF ':' type '=' CST_FLOAT ';'
           { 

                char value_str[12], buffer[100];
                int inserted = inserer($3, "Idf", "null", "false");
                if(inserted == -1) {
                    snprintf(buffer, sizeof(buffer), "Double declaration de l'entite %s", $3);
                    yyerrorSemantique(buffer);
                    yyerrok;
                } else {
                    // Vérification de la compatibilité de type
                    if (strcmp($5, "Float") != 0) {
                        snprintf(buffer, sizeof(buffer), "Type %s incompatible pour la constante flottante %s", $5, $3);
                        yyerrorSemantique(buffer);
                        yyerrok;
                    } else {
                        snprintf(value_str, sizeof(value_str), "%f", $7);
                        int i = update($3, "Float", "true", value_str, 1);
                        if(i == -1) {
                            snprintf(buffer, sizeof(buffer), "Erreur dans la declaration de constante %s", $3);
                            yyerror(buffer);
                            yyerrok;
                        } else {
                            printf("Declaration de constante flottante %s = %f\n", $3, $7);
                        }
                    }
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
                } else if(isConst($1) == 1) {
                    
                        snprintf(buffer,sizeof(buffer),"Erreur: La constante %s ne peut pas etre modifiee\n", $1);
                        yyerrorSemantique(buffer);
                        yyerrok;
                        // no problem
                } else {
                       // Type compatibility check
                    int type_error = 0;
                    if (strcmp(ts[i].TypeEntite, "Int") == 0) {
                        if ($3.is_var) {
                            int expr_idx = recherche($3.name);
                            if (expr_idx != -1 && strcmp(ts[expr_idx].TypeEntite, "Float") == 0) {
                                snprintf(buffer, sizeof(buffer), "Erreur: Impossible d'assigner un Float a un Int pour %s\n", $1);
                                yyerrorSemantique(buffer);
                                type_error = 1;
                            }
                        }
                    }

                    if (!type_error) {
                        printf("Affectation pour entite %s \n", $1);
                        if ($3.is_var) {
                            int expr_idx = recherche($3.name);
                            if (expr_idx != -1) {
                                update($1, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[expr_idx].Value, 1);
                            }
                        } else {
                            snprintf(buffer, sizeof(buffer), "%d", $3.value);
                            update($1, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", buffer, 1);
                        }                
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
                printf("Affectation pour tableau %s[%d] \n", $1, $3);
                if ($6.is_var) {
                     // Si c'est une variable, on récupère sa valeur de la table des symboles
                     int expr_idx = recherche($6.name);
                     if (expr_idx != -1) {
                         update($1, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[expr_idx].Value, ts[i].Length);
                     }
                 } else {
                     // Sinon c'est une valeur constante
                     snprintf(buffer, sizeof(buffer), "%d", $6.value);
                     update($1, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", buffer, ts[i].Length);
                 }
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
        {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!$1.is_var && !$3.is_var) {
                $$.value = $1.value + $3.value;
                $$.is_var = 0;
                $$.name = NULL;

                char buffer[20];
                snprintf(buffer, sizeof(buffer), "%d", $$.value);
                update("expr", "Int", "false", buffer, 1);
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                $$.is_var = 1;
                $$.name = strdup("expr");  // Nom fictif
                $$.value = 0;  // Valeur par défaut
            }
        }
        | expression '-' expression
        {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!$1.is_var && !$3.is_var) {
                $$.value = $1.value - $3.value;
                $$.is_var = 0;
                $$.name = NULL;
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                $$.is_var = 1;
                $$.name = strdup("expr");  // Nom fictif
                $$.value = 0;  // Valeur par défaut
            }
        }
        | expression '*' expression
        {
            // Pour les opérations simples, on calcule la valeur si on a des constantes
            if (!$1.is_var && !$3.is_var) {
                $$.value = $1.value * $3.value;
                $$.is_var = 0;
                $$.name = NULL;
            } else {
                // Sinon, on doit garder l'info que c'est une expression avec variables
                $$.is_var = 1;
                $$.name = strdup("expr");  // Nom fictif
                $$.value = 0;  // Valeur par défaut
            }
        }
        | expression '/' expression
        {
            // Vérifier division par zéro pour les constantes
            if (!$3.is_var && $3.value == 0) {
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Erreur: Division par zero detectee");
                yyerrorSemantique(buffer);
                yyerrok;
                $$.value = 0; // Valeur par défaut
                $$.is_var = 0;
                $$.name = NULL;
            }
            // Vérifier division par zéro pour les variables
            else if ($3.is_var) {
                int divisor_idx = recherche($3.name);
                if (divisor_idx != -1) {
                    // Vérifier si la valeur est "0" ou équivalent à 0
                    if (strcmp(ts[divisor_idx].Value, "0") == 0 || 
                        (strcmp(ts[divisor_idx].Value, "null") != 0 && atoi(ts[divisor_idx].Value) == 0)) {
                        char buffer[100];
                        snprintf(buffer, sizeof(buffer), "Erreur: Division par zero detectee avec la variable %s", $3.name);
                        yyerrorSemantique(buffer);
                        yyerrok;
                    }
                }
                $$.is_var = 1;
                $$.name = strdup("expr");
                $$.value = 0;
            }
            // Cas normal, division de constantes
            else if (!$1.is_var && !$3.is_var) {
                $$.value = $1.value / $3.value;
                $$.is_var = 0;
                $$.name = NULL;
            }
            else {
                $$.is_var = 1;
                $$.name = strdup("expr");
                $$.value = 0;
            }
        }
        | '(' expression ')'
        {
            $$ = $2;
        }
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
                $$.is_var = 0;
                $$.value = 0;
                $$.name = NULL;
            } else {
                printf("Expression pour entite %s \n",$1);
                $$.is_var = 1;
                $$.name = strdup($1);
                
                // Try to convert value to int if available
                if (strcmp(ts[i].Value, "null") != 0) {
                    $$.value = atoi(ts[i].Value);
                } else {
                    $$.value = 0;  // Default value
                }
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
                $$.is_var = 0;
                $$.value = 0;
                $$.name = NULL;
            } else if (ts[i].Length == 1) {
                snprintf(buffer, sizeof(buffer), "Erreur: La variable %s n'est pas un tableau\n", $1);
                yyerrorSemantique(buffer);
                erreur = 1;
                $$.is_var = 0;
                $$.value = 0;
                $$.name = NULL;
            } else {
                int index = $3;
                if (index < 0 || index >= ts[i].Length) {
                    snprintf(buffer, sizeof(buffer), "Erreur: L'indice %d est hors limites pour le tableau %s\n", index, $1);
                    yyerrorSemantique(buffer);
                    erreur = 1;
                    $$.is_var = 0;
                    $$.value = 0;
                    $$.name = NULL;
                }
            }

            if (!erreur) {
                printf("Utilisation du tableau %s[%d] dans une expression\n", $1, $3);
                $$.is_var = 1;
                $$.name = strdup($1);  // Name of array
                $$.value = 0;  // Default value, would need array access mechanism
            }
        }
        | CST_INT
        {
            $$.value = $1;
            $$.is_var = 0;
            $$.name = NULL;
        }
        | CST_FLOAT
        {
            $$.value = (int)$1;  // Convert to int for simplicity
            $$.is_var = 0;
            $$.name = NULL;
        }
        | error 
        {
        yyerror("Erreur dans l'expression");
        yyerrok;
        $$.is_var = 0;
        $$.value = 0;
        $$.name = NULL;
        }
        ;

        %%
/* Fonction d'affichage de la table des symboles */
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
    printf("Analyse du programme...\n");
    yyparse();  
    afficher();
    return 0;
}