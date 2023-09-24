%option noyywrap

%{
    #include <iostream>

    using namespace std;

    #include "parser.tab.hpp"
%}

%%


[a-zA-Z][a-zA-Z0-9]*                {return ID;}
[+-]?[0-9]+(\.[0-9]*)?              {return BROJ;}
[+*()$|'<>\[\],\n-]                 {return *yytext;}
":="                                {return DODELA;}
"=="                                {return EQ;}
"!="                                {return NEQ;}
[ \t]                               {}
.                                   {
                                        cerr << "Leksicka greska: " << yytext << endl;
                                        exit(EXIT_FAILURE);
                                    }

%%
