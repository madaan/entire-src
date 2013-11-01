%{
#include <string.h>
int line_count = 0, char_count = 0, word_count = 0;
%}

%%
[a-zA-Z0-9]+ {char_count = strlen(yytext) + char_count; word_count++;}
[ \t]+ {char_count = strlen(yytext) + char_count;}
\n {line_count++;char_count = strlen(yytext) + char_count;}
. ;
%%
int main(int argc, char *arv[])
{
yylex();
printf("\n\t Lines  : %d\n\t Words  : %d\n\t Characters (including whitespace and newline) : %d\n",line_count, word_count, char_count);
return 1;
}
