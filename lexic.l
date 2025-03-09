%{
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>
  
  int nb_ligne=1;
  int col;
  
  bool integer_validation(int number){
   if(number<=-32768 && number>=32768){
      return true;}
   return false;
  }

  bool idf_validation(char idf[], int length) {
    if (length > 14) return false;  // Vérifier la longueur
    if (idf[length - 1] == '_' || idf[0] == '_') return false;  // Vérifier le début et la fin
    
    int i;
    // Vérifier "__" sans accès hors limites
    for ( i = 0; i < length - 1; i++) {  
        if (idf[i] == '_' && idf[i + 1] == '_') return false;
    }
    return true;
  }
  
%}

/* Entite */

lettre [a-zA-Z]
chiffre [0-9]

/* IDF */
IDF ({lettre}|{chiffre}|_)+
/*done*/

/* CST */
CST_INT \([+-]{chiffre}+\)|{chiffre}+
/*done*/

CST_FLOAT \([+-]{chiffre}+\.{chiffre}+\)|{chiffre}+\.{chiffre}+
/* done */

/* COMMENTS */

COMMENT_LINE <!-[^\n]*-!>
/*done*/

COMMENTS_BLOCS "{-"[^\n]*(.|\n)*"-}"
/*done*/




%%
"Main Program" { col+=yyleng;printf("Main Program \n");}
"Var" {col+=yyleng; printf("debut de bloc de declaration \n");}
"BeginPg" {col+=yyleng; printf("debut de bloc de code \n");}
"EndPg;" {col+=yyleng; printf("fin du code \n");}

{COMMENTS_BLOCS} {col+=yyleng; printf("block de commentaire %s \n",yytext);}
{COMMENT_LINE} {col+=yyleng;printf("commentaire dans la ligne %d : %s \n",nb_ligne,yytext);}


"let" {col+=yyleng; printf("let \n");}
"@define" {col+=yyleng; printf("@define \n");}
"Const" {col+=yyleng; printf("Const \n");}
"Int" {col+=yyleng; printf("Int \n");}
"Float" {col+=yyleng; printf("Float \n");}

"if" {col+=yyleng; printf("if \n");}
"then" {col+=yyleng; printf("then \n");}
"else" {col+=yyleng; printf("else \n");}

"do" {col+=yyleng; printf("do \n");}
"while" {col+=yyleng; printf("while \n");}

"for" {col+=yyleng; printf("for \n");}
"from" {col+=yyleng; printf("from \n");}
"to" {col+=yyleng; printf("to \n");}
"step" {col+=yyleng; printf("step \n");}

"input" {col+=yyleng; printf("input \n");}
"output" {col+=yyleng; printf("output \n");}

; {col+=yyleng; printf(" ; \n"); }
= { col+=yyleng; printf("  = \n");}
, { col+=yyleng; printf("  , \n");}
: { col+=yyleng; printf(": \n");}
":=" { col+=yyleng; printf(":= \n");}
"AND" { col+=yyleng; printf(" AND \n");}
"OR" { col+=yyleng; printf("OR \n");}

"(" { col+=yyleng; printf(" ( \n");}
")" { col+=yyleng; printf(" ) \n");}

"{" { col+=yyleng; printf(" { \n");}
"}" { col+=yyleng; printf(" } \n");}

"[" { col+=yyleng; printf(" [ \n");}
] { col+=yyleng; printf("  ] \n");}

! { col+=yyleng; printf("  ! \n");}

">" { col+=yyleng; printf("  > \n");}
"<" { col+=yyleng; printf("  < \n");}
">=" { col+=yyleng; printf("  > \n");}
"<=" { col+=yyleng; printf("  < \n");}
"==" { col+=yyleng; printf("  == \n");}
"!=" { col+=yyleng; printf("  != \n");}

{IDF}  {
    
    if (idf_validation(yytext, yyleng)) {
        col += yyleng;
        printf("IDF FOUND %s \n", yytext);
    } else {
        printf("\nErreur lexicale sur l'entité %s a la ligne %d et la colonne %d\n", yytext, nb_ligne, col);
    }
}

{CST_INT}  { 
   if(integer_validation(atoi(yytext)) && yyleng<= 14){
    col+=yyleng;printf("CST_INT FOUND %s \n",yytext);
   }
   else{
    printf("\n IDF hors de la plage\n");
   }}

{CST_FLOAT}  {
   col+=yyleng;printf("CST_FLOAT FOUND %s \n",yytext);
   }

[ \t] 
\n   {nb_ligne++; col=1;}
. {printf("\n erreur lexicale sur l'entite %s a la ligne %d et la colonne %d\n", yytext,nb_ligne,col); return 0;}
%%
int main() 
{
  yylex();
  return 0;
}

