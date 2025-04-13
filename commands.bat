flex lexic.l
bison -d syntax.y
gcc lex.yy.c syntax.tab.c -o main
main.exe<test.txt