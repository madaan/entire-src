%{
/*
E : INT                     {$$ = 1.0 * $1;printf("res : %d\n$$ = %f\n%d\n", yylval, $$, $1); } ;*/
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
    float ST[30];
%}
%union 
{
        int iarg;
        float farg;
}
%token<iarg>  INT 
%token<iarg>  VAR
%token<farg> FLOAT
%type<farg> S
%type<farg> E
%left '-' '+'
%left '*' '/'
%%

S :
S : S '(' E ')' '\n'        {printf("%f\n", $3);} ;
   
S : S VAR '=' E '\n'            {ST[$2] = $4; printf("%f\n", $4);};

S : S E '\n'                {printf("%f\n", $2);} ;


S : S VAR'\n'              {printf("%f\n", ST[$2]);};

E : INT                     {$$ =  $1;};


E : FLOAT                   {$$ = 1.0 * $1;} ;
    
E : E '+' E                 {$$ = $1 + $3;} ;
    
E : E '-' E                 {$$ = $1 - $3;} ;

E : E '*' E                 {$$ = $1 * $3;} ;
    
E : E '/' E                 {
                                if($3 == 0) { yyerror("fatal : div by 0\n");}
                                $$ = $1 / $3;
                            } ;

E : '(' E ')'               {$$ = $2;} ;

E : VAR                     {$$ = ST[$1];};

E : VAR '=' E               {ST[$1] = $3;};

%%

void yyerror(char *s) 
{
    if(s == NULL) {
        printf("\nError parsing the input, check your expression and try again!\n");
    } else {
        printf("%s", s);
    }
}

int main()
{
    yyparse();
    return 0;
}
