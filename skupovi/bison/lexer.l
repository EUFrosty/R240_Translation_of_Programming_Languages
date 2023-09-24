%option noyywrap
%{
    #include <iostream>

    using namespace std;

    #include "parser.tab.hpp"

%}

%%

UniversalSet                    {return DOMEN;}
card                            {return CARD;}
check                           {return CHECK;}
[A-Z]                           {return ID;}
"print"                           {return PRINT_T;}
[+-]?[1-9][0-9]*                {return BROJ;}
".."                            {return DO;}
"\\/"                           {return UNIJA;}
"/\\"                           {return PRESEK;}
"\\"                            {return RAZLIKA;}
[{}();,=<:~]                     {return *yytext;}
[ \n\t]                         {}
.                               {
                                    cerr << "Leksicka greska: " << yytext << endl;
                                    exit(EXIT_FAILURE);
                                }




%%
