%{
#include <string.h>
%}
puct [,.?;'"!]
alpha [a-zA-Z]
space [ ]
lines [\n]+
%%
({alpha}+{space}*\n?)   {
                        
char *temp = malloc(yyleng + 1);
int i = yyleng;
while(yytext[i - 1] == ' ') {
i--;
}
while(i >= 0) { 
temp[i] = yytext[i];
i--;
}
printf("%s", temp);
//free(temp);
}

\n/\n ;
%%

int main()
{
yylex();
return 1;
}

