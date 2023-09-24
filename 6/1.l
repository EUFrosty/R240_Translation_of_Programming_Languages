%option noyywrap

%{
    //c ili c++ kod
    #include <stdio.h>
    #include <stdlib.h>

    int brojLinija = 0;
    int brojKaraktera = 0;

%}

%%

. {brojKaraktera++;}
\n {
    brojKaraktera++;
    brojLinija++;
    }

%%

int main(){

    yylex();

    printf("Broj karaktera: %d\n", brojKaraktera);
    printf("Broj linija: %d\n", brojLinija);

    exit(EXIT_SUCCESS);
    }
