%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "tokeni.h"
%}

%%

print               {return PRINT;}
".."                {return TT;}
[A-Z]               {return ID;}
[+-]?[1-9][0-9]*    {return BROJ;}
"{"                 {return OZ;}
"}"                 {return ZZ;}
","                 {return ZAREZ;}
";"                 {return TZ;}
"="                 {return DODELA;}
[ \t\n]             {}
.                   {
                        fprintf(stderr, "Leksicka greska: %s\n", yytext);
                        exit(EXIT_FAILURE);
                    }

%%
