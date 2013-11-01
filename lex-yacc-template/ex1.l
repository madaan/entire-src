%{
#include "y.tab.h"
//sg
/*
#define GLOBALTOK 1
#define HOSTTOK 2
#define OPT 3 
#define STRVAL 4 
#define LBRACE 5 
#define RBRACE 6 
#define QUOTE 7
#define SEMCOL 8
*/
%}

%%
global                      {return GLOBALTOK;}
host                        {return HOSTTOK;}
[a-zA-Z][_a-zA-Z0-9]+       {return OPT;}
[a-zA-Z/][a-zA-Z0-9_\-/.]+  {return STRVAL;}
\{                          {return LBRACE;}
\}                          {return RBRACE;}
\"                          {return QUOTE;}
;                           {return SEMCOL;}
[=\n]                       {return *yytext;}
%%

