%option noyywrap

%{
    #include "tokeni.h"

%}

%%


[a-zA-Z][a-zA-Z0-9]*        {return ID;}
[+-]?[0-9]+(\.[0-9]*)?      {return BROJ;}
":="                        {return DODELA;}
","                         {return ZAREZ;}
"<"                         {return OZ;}
">"                         {return ZZ;}
\n                          {return NOVIRED;}
[ \t]                       {}
.                           {
                                exit(EXIT_FAILURE);
                            }



%%
