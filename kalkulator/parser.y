%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern int yylex();

    void yyerror(char* s){
        fprintf(stderr, "Greska: %s\n", s);
        exit(EXIT_FAILURE);
        }
%}

%union {
    int k;
    float v;
    char* ime;
}

%left '+' '-'
%left '*' '/'
%right UMINUS

%token PRINT GEQ LEQ EQ NEQ
%token<v> BROJ
%token<v> ID
%type<k> logicka_naredba
%type<v> izraz

%start program
%%

program: program naredba
    | naredba
    ;

naredba: ID '=' izraz ';'       {$1 = $3;}
    | PRINT '(' izraz ')' ';'   {printf("%f\n", $3);}
    |logicka_naredba ';'        {printf("%s\n", $1);}
    ;

izraz: izraz '+' izraz          {$$=$1+$3;}
    | izraz '-' izraz           {$$=$1-$3;}
    | izraz '*' izraz           {$$=$1*$3;}
    | izraz '/' izraz           {$$=$1/$3;}
    | '-' izraz    %prec UMINUS {$$ = -$2;}
    | '(' izraz ')'             {$$ = $2;}
    | BROJ                      {$$ = $1;}
    | ID                        {$$ = $1;}
    ;

logicka_naredba: izraz '<' izraz    {$$ = ($1 < $3);}
    | izraz '>' izraz               {$$ = ($1 > $3);}
    | izraz GEQ izraz               {$$ = ($1 >= $3);}
    | izraz LEQ izraz               {$$ = ($1 <= $3);}
    | izraz EQ izraz                {$$ = ($1 == $3);}
    | izraz NEQ izraz               {$$ = ($1 != $3);}
    ;


%%

int main() {

    if (yyparse()==0){
        printf("Sve ok.\n");
    }else{
        fprintf(stderr, "Greska.\n");
    }
    exit(EXIT_SUCCESS);

}
