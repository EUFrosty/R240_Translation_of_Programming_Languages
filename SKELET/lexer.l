%option noyywrap

%{
    #include "tokeni.h"
%}

%%


[ \t\n] { }
.       {
            fprintf(stderr, "Leksicka greska: %d\n", yytext);
            exit(EXIT_FAILURE);
        }

%%
