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
"("     {return LEFT_BRACKET;}
")"     {return RIGHT_BRACKET;}

"sin"   {return SIN;}
"cos"   {return COS;}
"tan"   {return TAN;}

[0-9]+"!"  {sscanf(yytext,"%d!",&yylval); return FACTORIAL;}

"C"|"c"     {return COMB;}
"P"|"p"     {return PERM;}    
","     {return COMMA;}

"mod"   {return MOD;}
"%"     {return PERCENT;}
"ceil"     {return CEIL;}
"floor"     {return FLOOR;}
"^"     {return POW;}

"ANS"   {return ANS;}

[0-9]+ 	{sscanf(yytext,"%lf",&yylval);return NUMBER;}
[0-9]+\.[0-9]+ { sscanf(yytext,"%lf",&yylval); return NUMBER;}

\n  	{return EOL;}
[ \t] 	{/*空白忽略*/}
. 	{return yytext[0];}

%%
