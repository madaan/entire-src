%{
int line_count = 0;
%}

%%
\n {line_count++;}
. ;
%%
int main(int argc, char *arv[])
{
yylex();
printf("The total number of lines is %d\n", line_count);
return 1;
}
