%{
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "calc_function.h"
#include "output_file.h"
#define YYSTYPE double
static int answer = 0;
static char* str;

%}

%token FLOAT NUMBER ALPHABET
%token LEFT_PAREN RIGHT_PAREN COMMA EXCLA_MARK
%token SIN COS TAN
%token ADD SUB MUL DIV ABS
%token COMB PERM
%token DECIMAL2BINARY DECIMAL2OCTAL DECIMAL2HEX
%token EOL
%token ANS
%token MOD PERCENT CEIL FLOOR POW
%token GREATER LESS EQUAL

%%

calclist:/**/
  |calclist exp EOL { answer = $2; output_file_d($2); printf("= %lf\n",$2);}
  |calclist digit_convert EOL {output_file_s(str); printf("= %s\n", str);}
  |calclist cmp EOL {output_file_s(str); printf("= %s\n", str);}
  ;

digit_convert:exp {$$ = $1;}
  |DECIMAL2BINARY exp { str = decimal_to_binary($2);}
  |DECIMAL2HEX exp { str = decimal_to_hex($2);}
  |DECIMAL2OCTAL exp { str = decimal_to_octal($2);}
  ;

cmp:exp {$$=$1;}
  |cmp GREATER exp{str = $1 > $3? "true":"false";}
  |cmp LESS exp{str = $1 < $3? "true":"false";}
  |cmp EQUAL exp{str = $1 == $3? "true":"false";}

exp:factor {$$ = $1;}
  |exp ADD factor{$$=$1+$3;}
  |exp SUB factor{$$=$1-$3;}
  |exp PERCENT{$$=0.01*$1;}
  |SUB factor{$$=-$2;}
  |ADD factor{$$= $2;}
  |SIN factor {$$=sin($2);}
  |COS factor {$$=cos($2);}
  |TAN factor {$$=tan($2);}
  |exp EXCLA_MARK {$$ = factorial((int)$1);}
  ;

factor:term {$$=$1;}
  |factor MUL term{$$=$1*$3;}
  |factor DIV term{if($3 == 0) 
                    yyerror(0, "divide by zero");
                    $$=$1/$3;}
  |factor MOD term{$$=(int)$1%(int)$3;}
  |factor POW term{$$=pow($1, $3);}
  ;

term:NUMBER {$$=$1;}
  |FLOAT {$$=$1;}
  |ANS   {$$=answer;}
  |ABS exp ABS{$$=$2>=0?$2:-$2;}
  |LEFT_PAREN exp RIGHT_PAREN{$$=$2;}
  |PERM LEFT_PAREN exp COMMA exp RIGHT_PAREN{$$ = permutation($3, $5);}
  |COMB LEFT_PAREN exp COMMA exp RIGHT_PAREN{$$ = combination($3, $5);}
  |CEIL LEFT_PAREN exp RIGHT_PAREN{$$=$3>=0?(int)$3+1:(int)$3;}
  |FLOOR LEFT_PAREN exp RIGHT_PAREN{$$=$3>=0?(int)$3:(int)$3-1;}
  ;

%%

main(int argc,char **argv){
  clear_file();
	yyparse();
}

yyerror(char *s)
{
 fprintf(stderr,"error:%s\n",s);
}