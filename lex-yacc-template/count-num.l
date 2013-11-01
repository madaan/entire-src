%{
int int_count = 0;
int dec_count = 0;
%}
digits  [0-9]+
dot  [.]
%%
{digits} int_count++;
({digits}{dot}{digits}) dec_count++;
\n /*Ignore newlines*/;
. /*And everything else*/;
%%
int main(int argc, char *arv[])
{
yylex();
printf("Integers : %d\nFloating point numbers :  %d\n", int_count, dec_count);
return 1;
}
