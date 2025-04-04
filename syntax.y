%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
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
              if (nb_erreurs == 0) {
                  printf("Programme valide !\n");
              } else {
                  printf("Programme invalide. %d erreur(s) detectee(s).\n", nb_erreurs);
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
         { printf("Declaration de variables %s de type %s\n",$2,$4);

                
                  char *token = strtok($2, ", ");
                  while (token != NULL) {
                    update(token, $4, "false","null");
                    token = strtok(NULL, ", ");
                                         }
           
         }
         | LET var_list ':' '[' type ';' CST_INT ']' ';'
         { printf("Declaration de tableau %s de type %s\n",$2,$5);

         char *token = strtok($2, ", ");
                  while (token != NULL) {
                    update(token, $5, "false","null");
                    token = strtok(NULL, ", ");
                                        }
          
         }
         /* Gestion des erreurs */
         | LET var_list ':' '[' type error ';'
         { 
             yyerror("Erreur: Mauvaise declaration du tableau. Syntaxe attendue: [type;taille]");
             yyerrok;
         }
         | LET var_list ':' error ';'
         { 
             yyerror("Erreur: Type invalide dans la declaration de variable");
             yyerrok;
         }
         | LET error
         {
             yyerror("Erreur dans la declaration de variable");
             yyerrok;
         }
         ;

/* Liste des variables */
var_list : IDF ',' var_list {
    char* buffer = malloc(strlen($1) + strlen($3) + 3);
    sprintf(buffer, "%s, %s", $1, $3);
    $$ = buffer;
}
| IDF {
    $$ = strdup($1);  // Copie du nom
}
| error {
    yyerror("Erreur dans la liste des variables");
    yyerrok;
    $$ = strdup("???");
};


/* Declaration de constantes */
const_decl : DEFINE CONST IDF ':' type '=' CST_INT ';'
           { 
            printf("Declaration de constante entiere: %s = %d\n", $3,$7);
            char value_str[12];
            snprintf(value_str, sizeof(value_str), "%d", $7);
            update($3, "Int", "true", value_str);
            }
           | DEFINE CONST IDF ':' type '=' CST_FLOAT ';'
           { printf("Declaration de constante reelle %s = %f\n ",$3,$7);
           
                char value_str[32]; 
                snprintf(value_str, sizeof(value_str), "%.2f", $7); 
                update($3, "Float", "true", value_str);
              
            }
           | DEFINE CONST IDF ':' type '=' error
           { 
               yyerror("Erreur: Valeur de constante invalide ou point-virgule manquant");
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
| error {
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
            { printf("Affectation simple\n"); }
            | IDF '[' expression ']' ASSIGN expression ';'
            { printf("Affectation dans un tableau\n"); }
            | IDF ASSIGN expression error
            { 
                yyerror("Erreur: Point-virgule manquant apres l'affectation");
                yyerrok;
            }
            | IDF '[' expression ']' ASSIGN expression error
            {
                yyerror("Erreur: Point-virgule manquant apres l'affectation de tableau");
                yyerrok;
            }
            | error ASSIGN expression ';'
            {
                yyerror("Erreur: Identificateur invalide dans l'affectation");
                yyerrok;
            }
            ;

condition : IF '(' expression ')' THEN '{' instructions '}'
          { printf("Condition if sans else\n"); }
          | IF '(' expression ')' THEN '{' instructions '}' ELSE '{' instructions '}'
          { printf("Condition if-else\n"); }
          | IF '(' error ')' THEN '{' instructions '}'
          {
              yyerror("Erreur dans la condition du if");
              yyerrok;
          }
          | IF error
          {
              yyerror("Erreur: Syntaxe incorrecte pour la condition if");
              yyerrok;
          }
          ;

boucle_do : DO '{' instructions '}' WHILE '(' expression ')' ';'
          { printf("Boucle do-while\n"); }
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
           { printf("Boucle for\n"); }
           | FOR error
           {
               yyerror("Erreur: Syntaxe incorrecte pour la boucle for");
               yyerrok;
           }
           ;

lecture : INPUT '(' IDF ')' ';'
        { printf("Instruction input\n"); }
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
         { printf("Instruction output\n"); }
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
           | expression NE expression
           | IDF
           | IDF '[' expression ']'
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
    printf("Erreur Syntaxique a la ligne %d, colonne %d: %s\n", nb_ligne, col, s);
    nb_erreurs++;
    return 0;
}

int main() {
    printf("Analyse syntaxique...\n");
    yyparse();  
    afficher();
    return 0;
}