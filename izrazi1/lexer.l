%option noyywrap

%{
        #include <iostream>
        #include <cstdlib>

        using namespace std;

        #include "parser.tab.hpp"

%}

%%


list                            {return LIST_T;}
int                             {return INT_T;}
print                           {return PRINT_T;}
_[a-zA-Z][a-zA-Z0-9]*           {return ID;}
0x[0-9a-fA-F]+                  {return BROJ;}
[1-9][0-9]*                     {return BROJ;}
0[0-7]*                         {return BROJ;}
"<<"                            {return SL;}
">>"                            {return SR;}
"=="                            {return EQ;}
"!="                            {return NEQ;}
[+*/()=%,\n&|^~\[\]-]           {return *yytext;}
[ \t]                           {}
.                               {
                                    cerr << "Leksicka greska: " << yytext << endl;
                                    exit(EXIT_FAILURE);
                                }
