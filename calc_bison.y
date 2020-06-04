%{
#include <stdio.h>
#include <ctype.h>
#include "calc_function.h"
#define YYSTYPE double
static int answer = 0;

%}

%token FLOAT NUMBER
%token LEFT_BRACKET RIGHT_BRACKET COMMA
%token SIN COS TAN
%token ADD SUB MUL DIV ABS
%token FACTORIAL 
%token COMB PERM
%token EOL
%token ANS

%%

calclist:/**/
  |calclist exp EOL { answer = $2; printf("= %lf\n",$2);}
  ;

exp:factor {$$ = $1;}
  |exp ADD factor{$$=$1+$3;}
  |exp SUB factor{$$=$1-$3;}
  |SUB factor{$$=-$2;}
  |ADD factor{$$= $2;}
  ;

factor:term {$$=$1;}
  |factor MUL term{$$=$1*$3;}
  |factor DIV term{$$=$1/$3;}
  ;

term:NUMBER {$$=$1;}
  |FLOAT {$$=$1;}
  |ANS   {$$=answer;}
  |ABS exp ABS{$$=$2>=0?$2:-$2;}
  |LEFT_BRACKET exp RIGHT_BRACKET{$$=$2;}
  |PERM LEFT_BRACKET exp COMMA exp RIGHT_BRACKET{$$ = permutation($3, $5);}
  |COMB LEFT_BRACKET exp COMMA exp RIGHT_BRACKET{$$ = combination($3, $5);}
  |FACTORIAL{ $$ = factorial($1);}
  ;

%%

main(int argc,char **argv){
	yyparse();
}

yyerror(char *s)
{
 fprintf(stderr,"error:%s\n",s);
}


