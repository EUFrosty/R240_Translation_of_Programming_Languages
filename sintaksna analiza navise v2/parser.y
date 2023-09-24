%{

    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();

    void yyerror(char* s) {
        fprintf(stderr, "sintaksna greska: %s\n", s);
        exit(EXIT_FAILURE);
    }
%}

%union {
    float v;
    }

%left '+' '-'
%left '*' '/'
%right UMINUS

%token<v> BROJ

%type<v> e

%start program

%%

program: program naredba        {}
    | naredba                   {}
    ;

naredba: e ';'                  {printf("Vrednost izraza: %.2f\n", $1);}
    ;
e: e '+' e                  {$$ = $1+$3;}
    | e '-' e               {$$ = $1-$3;}
    | e '*' e               {$$ = $1*$3;}
    | e '/' e               {$$ = $1/$3;}
    | '-' e  %prec UMINUS   {$$ = -$2;}
    | '(' e ')'             {$$ = $2;}
    | BROJ                  {$$ = $1;}
    ;

%%

int main(){
    if(yyparse() == 0) {
        printf("sve ok.\n");
    }else{
        printf("Sintaksna greska.\n");
    }
    exit(EXIT_SUCCESS);
}
