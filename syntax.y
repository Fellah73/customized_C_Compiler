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
         { printf("Declaration de variables\n"); }
         | LET var_list ':' '[' type ';' CST_INT ']' ';'
         { printf("Declaration de tableau\n"); }
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
var_list : IDF ',' var_list
         | IDF
         | error
         {
             yyerror("Erreur dans la liste des variables");
             yyerrok;
         }
         ;

/* Declaration de constantes */
const_decl : DEFINE CONST IDF ':' type '=' CST_INT ';'
           { printf("Declaration de constante entiere\n"); }
           | DEFINE CONST IDF ':' type '=' CST_FLOAT ';'
           { printf("Declaration de constante reelle\n"); }
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
type : INT
     | FLOAT
     | error
     {
         yyerror("Type non reconnu");
         yyerrok;
     }
     ;

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
    return 0;
}