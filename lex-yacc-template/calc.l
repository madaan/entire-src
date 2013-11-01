%{
/*here we need to train the lex to catch integers*/
/*Before doing that, we need to set up the yyval 
to make sure that the correct value is pushed in the 
value stack*/

/*({digits}{dot}{printf("yytext = %s\nyyval.iarg = %d\n", yytext, atoi(yytext));digits}) {yylval.farg = atof(yytext);yylval.type = FLOAT; return FLOAT;}*/
#include "y.tab.h"
#include <stdlib.h>
%}

digits [0-9]+
dot [.]

alpha [a-z]

%%
({digits}) {yylval.iarg = atoi(yytext);return INT;}
({digits}{dot}{digits}) {yylval.farg = atof(yytext); return FLOAT;}
[a-z] {yylval.iarg = *yytext - 'a';return VAR;}
[-=+*/\n()]      return *yytext; 

[ \t]     ; /* skip whitespace */ 

.           yyerror("invalid character\n"); 


%%
