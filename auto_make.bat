@echo off
flex calc_flex.l
bison -d calc_bison.y
gcc calc_bison.tab.c calc_function.c lex.yy.c output_file.c -lfl
.\a.exe < .\test_code.txt
FC ".\cmp_test_code.txt" ".\out_test_code.txt"
.\a.exe