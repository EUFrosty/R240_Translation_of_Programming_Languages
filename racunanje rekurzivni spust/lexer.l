%option noyywrap

%{
    #include "tokeni.h"
    extern int yylval;
%}

%%

[0-9]+      {
                yylval = atoi(yytext);
                return BROJ;
            }
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return PUTA;}
"/"         {return PODELJENO;}
"("         {return OZ;}
")"         {return ZZ;}
[ /t/n]     { }
.           {
                fprintf(stderr, "greska %s\n", yytext);
                exit(EXIT_FAILURE);
            }
