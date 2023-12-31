%option noyywrap

%{
    #include "parser.tab.h"
%}

%%

[0-9]+      {
                yylval.v = atoi(yytext);
                return BROJ;
            }
[+*();]     {return *yytext;}
[ \t\n]     { }
.           {
                fprintf(stderr, "Leksicka greska: %s\n", yytext);
                exit(EXIT_FAILURE);
            }

%%

