%{
  #include <stdio.h>
  #include <string.h>
  #include <stdbool.h>
  #include <stdlib.h> 
  #include <ctype.h>  
  #include "syntax.tab.h"
  
  typedef struct {
    bool isValid;
    int value;
  } IntResult;
 
  int nb_ligne=1;
  int col=1;
  
  IntResult integer_validation(char number[]) {
    int length = strlen(number);
    char clean_number[20];
    int index = 0;

    if (number[0] == '(' && number[length - 1] == ')') {
      int i;
      for (i = 1; i < length - 1; i++) {
        clean_number[index++] = number[i];
      }
      clean_number[index] = '\0';
    } else {
      strcpy(clean_number, number);
    }

    if (clean_number[0] == '+') {
      memmove(clean_number, clean_number + 1, strlen(clean_number));
    }

    int value = atoi(clean_number);

    IntResult result;
    result.isValid = true;
    result.value = value;

    if (value < -32768 || value > 32767) {
      result.isValid = false;
      result.value = 0;
    }
    return result;
  }

  float float_validation(char number[]) {
    int length = strlen(number);
    char clean_number[20];
    int index = 0;

    if (number[0] == '(' && number[length - 1] == ')') {
      int i;
      for (i = 1; i < length - 1; i++) {
        clean_number[index++] = number[i];
      }
      clean_number[index] = '\0';
    } else {
      strcpy(clean_number, number);
    }

    if (clean_number[0] == '+') {
      memmove(clean_number, clean_number + 1, strlen(clean_number));
    }

    float value = atof(clean_number);

    return value;
  }
  
  bool idf_validation(char idf[], int length) {
    if (length > 14) return false; 
    if (idf[length - 1] == '_' || !isalpha(idf[0])) return false; 
    
    int i;
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
COMMENT_LINE "<!-"[^\n]*"-!>"
COMMENTS_BLOCS "{--"([^-]|"-"[^-])*"--}"

%%
"MainPrgm" { col+=yyleng;  inserer(yytext,"motCle","null", "false"); return MAINPRGM; }
"Var" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return VAR; }
"BeginPg" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return BEGINPG; }
"EndPg" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return ENDPG; }

{COMMENTS_BLOCS} { col+=yyleng; /* Ignorer les commentaires */ }
{COMMENT_LINE} { col+=yyleng; /* Ignorer les commentaires */ }

"let" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return LET; }
"@define" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return DEFINE; }
"Const" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return CONST; }
"Int" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return INT; }
"Float" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return FLOAT; }

"if" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return IF; }
"then" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return THEN; }
"else" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return ELSE; }

"do" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return DO; }
"while" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return WHILE; }

"for" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return FOR; }
"from" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return FROM; }
"to" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return TO; }
"step" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return STEP; }

"input" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return INPUT; }
"output" { col+=yyleng; inserer(yytext,"motCle","null", "false"); return OUTPUT; }

"+" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '+'; }
"-" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '-'; }
"*" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '*'; }
"/" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '/'; }
";" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ';'; }
"=" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '='; }
"," { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ','; }
":" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ':'; }
":=" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ASSIGN; }
"AND" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return AND; }
"OR" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return OR; }

"(" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '('; }
")" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ')'; }
"{" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '{'; }
"}" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '}'; }
"[" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '['; }
"]" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return ']'; }
"!" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return '!'; }

">" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return GT; }
"<" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return LT; }
">=" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return GE; }
"<=" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return LE; }
"==" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return EQ; }
"!=" { col+=yyleng; inserer(yytext, "separateur", "null", "false"); return NE; }

{IDF} {
  if (idf_validation(yytext, yyleng)) {
    col += yyleng;
    yylval.str = strdup(yytext);
    return IDF;
  } else {
    printf("\nErreur lexicale sur l'entite %s a la ligne %d et la colonne %d\n", yytext, nb_ligne, col);   
  }
}

{CST_INT} {
  int value = atoi(yytext);

  if (integer_validation(yytext).isValid) {
    col+=yyleng;
    yylval.entier = integer_validation(yytext).value;
    return CST_INT;
  } else {
    printf("\nErreur lexicale: Entier hors plage [-32768, 32767] a la ligne %d et la colonne %d\n", nb_ligne, col);
  }
}

{CST_FLOAT} {
  if (float_validation(yytext)) {
    col+=yyleng;
    yylval.reel = float_validation(yytext);
    return CST_FLOAT;
  } else {
    printf("\nErreur lexicale: Float mal forme a la ligne %d et la colonne %d\n", nb_ligne, col);
  }
}

[ \t] { col+=yyleng; } 
\n { nb_ligne++; col=1; } 

. {
  printf("\nErreur lexicale sur l'entite %s a la ligne %d et la colonne %d\n", yytext, nb_ligne, col);
  col++;
}

%%
int yywrap() {return 1;}
