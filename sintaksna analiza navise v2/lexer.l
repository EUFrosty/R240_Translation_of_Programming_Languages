%option noyywrap

%{
    #include "parser.tab.h"

%}

%%

[0-9]+(\.[0-9*])?   {
                        yylval.v=atof(yytext);
                        return BROJ;
                    }

[+*/();-]           {return *yytext;}
[ \t\n]             { }
.                   {
                        fprintf(stderr, "Greska: %s\n", yytext);
                        exit(EXIT_FAILURE);
                    }

%%
