#include "tokeni.h"

extern int yylex();
int preduvid = 0;

void program(void);
void programP(void);
void naredba(void);
void ostatak(void);
void ostatak2(void);
void polinom(void);
void lista(void);
void listaP(void);

int main(){

    preduvid = yylex();
    program();
    if (preduvid != EOI){
        printf("NOT OK\n");
        exit(EXIT_SUCCESS);
    }

    printf("OK\n");
    exit(EXIT_SUCCESS);
}

void program(void){
    if (preduvid == ID || preduvid == OZ){
        naredba();
        programP();
    }else{
        exit(EXIT_FAILURE);
    }
}
void programP(void){
    if(preduvid == ID || preduvid == OZ){
        naredba();
        programP();
    }else if (preduvid == EOI){
    }else{
        exit(EXIT_FAILURE);
    }
}
void naredba(void){
    if (preduvid == OZ){
        polinom();
        if (preduvid != NOVIRED){
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
    }else if (preduvid == ID){
        preduvid = yylex();
        ostatak();
    }else{
        exit(EXIT_FAILURE);
    }
}
void ostatak(void){
    if (preduvid == NOVIRED){
        preduvid = yylex();
    }else if (preduvid == DODELA){
        preduvid = yylex();
        ostatak2();
    }else{
        exit(EXIT_FAILURE);
    }
}
void ostatak2(void){
    if (preduvid == OZ){
        polinom();
        if (preduvid != NOVIRED){
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
    }else if (preduvid == ID){
        preduvid = yylex();
        if (preduvid != NOVIRED){
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
    }else{
        exit(EXIT_FAILURE);
    }
}
void polinom(void){
    if (preduvid == OZ){
        preduvid = yylex();
        lista();
        if (preduvid != ZZ){
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
    }else{
        exit(EXIT_FAILURE);
    }
}

void lista(void){
    if (preduvid == BROJ){
        preduvid = yylex();
        listaP();
    }else{
        exit(EXIT_FAILURE);
    }
}
void listaP(void){
    if (preduvid == ZAREZ){
        preduvid = yylex();
        if (preduvid != BROJ){
            exit(EXIT_FAILURE);
        }
        preduvid = yylex();
        listaP();
    }else if (preduvid == ZZ){
    }else{
        exit(EXIT_FAILURE);
    }
}
