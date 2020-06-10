%{
#include "calc_bison.tab.h"
#include <math.h>
%}

%%

"+"   	{return ADD;}
"-"   	{return SUB;}
"*"   	{return MUL;}
"/"   	{return DIV;}
"|"   	{return ABS;}
"("     {return LEFT_PAREN;}
")"     {return RIGHT_PAREN;}

"sin"   {return SIN;}
"cos"   {return COS;}
"tan"   {return TAN;}

"!"     {return EXCLA_MARK;}

"Decimal_to_Binary" {return DECIMAL2BINARY;}
"Decimal_to_Octal" {return DECIMAL2OCTAL;}
"Decimal_to_Hex" {return DECIMAL2HEX;}


"C"|"c"     {return COMB;}
"P"|"p"     {return PERM;}    
","     {return COMMA;}

"mod"   {return MOD;}
"fmod"  {return FMOD;}
"%"     {return PERCENT;}
"ceil"     {return CEIL;}
"floor"     {return FLOOR;}
"^"     {return POW;}
"log"   {return LOG;}
"ln"    {return LN;}


">"     {return GREATER;}
"<"     {return LESS;}
"="     {return EQUAL;}

"ANS"   {return ANS;}
"vec"   {return VEC;}

[0-9]+ 	{sscanf(yytext,"%lf",&yylval);return NUMBER;}
[0-9]+\.[0-9]+ { sscanf(yytext,"%lf",&yylval); return NUMBER;}
[A-Z]+ 	{return ALPHABET;}

\n  	{return EOL;}
[ \t] 	{/*空白忽略*/}
. 	{return yytext[0];}

%%
