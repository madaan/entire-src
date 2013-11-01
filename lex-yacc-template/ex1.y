%{
#include <stdio.h>
%}

%token GLOBALTOK
%token HOSTTOK
%token OPT
%token STRVAL
%token LBRACE
%token RBRACE
%token QUOTE
%token SEMCOL

%%
CONFIG : 

CONFIG : CONFIG GLOBAL HOSTSECT         {printf("Globaltok");};

GLOBAL : GLOBALTOK LBRACE STMTS RBRACE SEMCOL;

HOSTSECT : 

HOSTSECT : HOSTSECT HOSTDEF '\n' {printf("Hosts\n");};

HOSTDEF : HOSTTOK QUOTEDNAME LBRACE STMTS RBRACE SEMCOL;

QUOTEDNAME : QUOTE STRVAL QUOTE;

STMTS : 

STMTS : STMTS STMT '\n';

STMT : OPT '=' STRVAL;
       
    
%%
int yyerror(char *ch)
{
if(ch == NULL) {
    printf("Syntax Error\n");
} else {
    printf("%s\n", ch);
}
}

int main()
{
yyparse();
}
