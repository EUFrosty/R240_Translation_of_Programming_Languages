#include <stdio.h>
#include <stdlib.h>

#include "tokeni.h"

extern int yylex();

int yylval = 0;
int preduvid;

int E(void);
int EP(int nasledjen);
int T(void);
int TP(int nasledjen);
int F(void);

int main(){
    preduvid = yylex();

    int r = E();

    if(preduvid == EOI){
        printf("SVE OK: %d\n", r);
    }else{
        printf("greska\n");
    }
    exit(EXIT_SUCCESS);
}

int E(void){
    if (preduvid == BROJ || preduvid == OZ){
        int nasledjen = T();
        return EP(nasledjen);
    }else{
        fprintf(stderr, "sintaksna greska\n");
        exit(EXIT_FAILURE);
    }
}

int EP(int nasledjen){
    if(preduvid == PLUS){
        preduvid = yylex();
        int rez = nasledjen + T();

        return EP(rez);
    }else if( preduvid == MINUS){
        preduvid = yylex();
        int rez = nasledjen - T();

        return EP(rez);
    }else if (preduvid == EOI || preduvid == ZZ){
        return nasledjen;
    }else{
        fprintf(stderr, "sintaksna greska\n");
        exit(EXIT_FAILURE);
    }
}

int T(void){
    if (preduvid == BROJ || preduvid == OZ){
        int nasledjen = F();
        return TP(nasledjen);
    }else{
        fprintf(stderr, "sintaksna greska\n");
        exit(EXIT_FAILURE);
    }
}

int TP(int nasledjen){
    if(preduvid == PUTA){
        preduvid = yylex();
        int rez = nasledjen * F();

        return TP(rez);
    }else if( preduvid == PODELJENO){
        preduvid = yylex();
        int rez = nasledjen / F();

        return TP(rez);
    }else if (preduvid == EOI || preduvid == ZZ || preduvid == MINUS || preduvid == PLUS){
        return nasledjen;
    }else{
        fprintf(stderr, "sintaksna greska\n");
        exit(EXIT_FAILURE);
    }
}

int F(void){
    if (preduvid == OZ){
        preduvid = yylex();
        int rez = E();
        if (preduvid != ZZ){
            fprintf(stderr, "sintaksna greska\n");
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
        return rez;
    }else if (preduvid == BROJ){
        int rez = yylval;
        preduvid = yylex();
        return rez;
    }else{
        fprintf(stderr, "sintaksna greska\n");
        exit(EXIT_FAILURE);
    }

}






























