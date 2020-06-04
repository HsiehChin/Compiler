%{
#include <stdio.h>
#include <ctype.h>
#include<math.h>
#include "calc_function.h"
#define YYSTYPE double
static int answer = 0;

%}

%token FLOAT NUMBER
%token LEFT_PAREN RIGHT_PAREN COMMA EXCLA_MARK
%token SIN COS TAN
%token ADD SUB MUL DIV ABS
%token COMB PERM
%token EOL
%token ANS
%token MOD PERCENT CEIL FLOOR POW

%%

calclist:/**/
  |calclist exp EOL { answer = $2; printf("= %lf\n",$2);}
  ;

exp:factor {$$ = $1;}
  |exp ADD factor{$$=$1+$3;}
  |exp SUB factor{$$=$1-$3;}
  |exp PERCENT{$$=0.01*$1;}
  |SUB factor{$$=-$2;}
  |ADD factor{$$= $2;}
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
  |NUMBER EXCLA_MARK {$$ = factorial((int)$1);}
  |ABS exp ABS{$$=$2>=0?$2:-$2;}
  |LEFT_PAREN exp RIGHT_PAREN{$$=$2;}
  |PERM LEFT_PAREN exp COMMA exp RIGHT_PAREN{$$ = permutation($3, $5);}
  |COMB LEFT_PAREN exp COMMA exp RIGHT_PAREN{$$ = combination($3, $5);}
  |CEIL LEFT_PAREN exp RIGHT_PAREN{$$=$3>=0?(int)$3+1:(int)$3;}
  |FLOOR LEFT_PAREN exp RIGHT_PAREN{$$=$3>=0?(int)$3:(int)$3-1;}
  ;

%%

main(int argc,char **argv){
	yyparse();
}

yyerror(char *s)
{
 fprintf(stderr,"error:%s\n",s);
}


