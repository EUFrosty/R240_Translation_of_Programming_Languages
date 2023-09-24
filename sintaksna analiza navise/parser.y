
%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();

    void yyerror(char* s){
        fprintf(stderr, "Greska: %s\n", s);
        exit(EXIT_FAILURE);
    }
%}

%union{
    int v;
}

%token<v> BROJ

%type<v> f e t

%start program

%%

program: program naredba    {}
        | naredba           {}
        ;
naredba: e ';'              {printf("vrednost izraza : %d\n", $1); }
        ;
e: e '+' t                  {$$ = $1+$3;}
        | t                 {$$ = $1;}
        ;
t: t '*' f                  {$$ = $1*$3;}
        | f                 {$$ = $1;}
        ;
f: '(' e ')'                {$$ = $2;}
        | BROJ              {$$ = $1;}
        ;
%%

int main(){
    if (yyparse() == 0){
        printf("Sve ok. \n");
    }else {
        printf("Greska.\n");
    }

    exit(EXIT_SUCCESS);
}
