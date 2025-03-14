%{
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>
  #include <ctype.h>  
  #include "syntax.tab.h"
  
  int nb_ligne=1;
  int col=1;
  
  bool integer_validation(int number){
    if(number < -32768 || number > 32767){
      return false;
    }
    return true;
  }
  
  bool idf_validation(char idf[], int length) {
    if (length > 14) return false;  // Vérifier la longueur
    if (idf[length - 1] == '_' || !isalpha(idf[0])) return false;  // Vérifier le début et la fin
    
    int i;
    // Verifier "__" sans acces hors limites
    for (i = 0; i < length - 1; i++) {
      if (idf[i] == '_' && idf[i + 1] == '_') return false;
    }
    return true;
  }
%}

/* Entites */
lettre [a-zA-Z]
chiffre [0-9]

/* CST */
CST_INT \([+-]{chiffre}+\)|{chiffre}+
CST_FLOAT \([+-]{chiffre}+\.{chiffre}+\)|{chiffre}+\.{chiffre}+

/* IDF */
IDF {lettre}({lettre}|{chiffre}|_)*

/* COMMENTS */
COMMENT_LINE "< !-"[^\n]*"-!>"
COMMENTS_BLOCS "{--"([^-]|"-"[^-])*"--}"

%%
"MainPrgm" { col+=yyleng; return MAINPRGM; }
"Var" { col+=yyleng; return VAR; }
"BeginPg" { col+=yyleng; return BEGINPG; }
"EndPg" { col+=yyleng; return ENDPG; }

{COMMENTS_BLOCS} { col+=yyleng; /* Ignorer les commentaires */ }
{COMMENT_LINE} { col+=yyleng; /* Ignorer les commentaires */ }

"let" { col+=yyleng; return LET; }
"@define" { col+=yyleng; return DEFINE; }
"Const" { col+=yyleng; return CONST; }
"Int" { col+=yyleng; return INT; }
"Float" { col+=yyleng; return FLOAT; }

"if" { col+=yyleng; return IF; }
"then" { col+=yyleng; return THEN; }
"else" { col+=yyleng; return ELSE; }

"do" { col+=yyleng; return DO; }
"while" { col+=yyleng; return WHILE; }

"for" { col+=yyleng; return FOR; }
"from" { col+=yyleng; return FROM; }
"to" { col+=yyleng; return TO; }
"step" { col+=yyleng; return STEP; }

"input" { col+=yyleng; return INPUT; }
"output" { col+=yyleng; return OUTPUT; }

"+" { col+=yyleng; return '+'; }
"-" { col+=yyleng; return '-'; }
"*" { col+=yyleng; return '*'; }
"/" { col+=yyleng; return '/'; }
";" { col+=yyleng; return ';'; }
"=" { col+=yyleng; return '='; }
"," { col+=yyleng; return ','; }
":" { col+=yyleng; return ':'; }
":=" { col+=yyleng; return ASSIGN; }
"AND" { col+=yyleng; return AND; }
"OR" { col+=yyleng; return OR; }

"(" { col+=yyleng; return '('; }
")" { col+=yyleng; return ')'; }
"{" { col+=yyleng; return '{'; }
"}" { col+=yyleng; return '}'; }
"[" { col+=yyleng; return '['; }
"]" { col+=yyleng; return ']'; }
"!" { col+=yyleng; return '!'; }

">" { col+=yyleng; return GT; }
"<" { col+=yyleng; return LT; }
">=" { col+=yyleng; return GE; }
"<=" { col+=yyleng; return LE; }
"==" { col+=yyleng; return EQ; }
"!=" { col+=yyleng; return NE; }

{IDF} {
  if (idf_validation(yytext, yyleng)) {
    col += yyleng;
    yylval.str = strdup(yytext);
    return IDF;
  } else {
    printf("\nErreur lexicale sur l'entité %s à la ligne %d et la colonne %d\n", yytext, nb_ligne, col);
  }
}

{CST_INT} {
  int value = atoi(yytext);
  if (integer_validation(value)) {
    col+=yyleng;
    yylval.entier = value;
    return CST_INT;
  } else {
    printf("\nErreur lexicale: Entier hors plage [-32768, 32767] à la ligne %d et la colonne %d\n", nb_ligne, col);
  }
}

{CST_FLOAT} {
  col+=yyleng;
  yylval.reel = atof(yytext);
  return CST_FLOAT;
}

[ \t] { col+=yyleng; } /* Ignorer les espaces et tabulations */
\n { nb_ligne++; col=1; } /* Nouvelle ligne */

. {
  printf("\nErreur lexicale sur l'entité %s à la ligne %d et la colonne %d\n", yytext, nb_ligne, col);
  col++;
}

%%
int yywrap() {return 1;}