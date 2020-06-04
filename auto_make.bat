@echo off
flex calc_flex.l
bison -d calc_bison.y
gcc calc_bison.tab.c calc_function.c lex.yy.c -lfl
.\a.exe