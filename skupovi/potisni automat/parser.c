#include "tokeni.h"

#define MAX (256)

extern int yylex();

int stek[MAX];
int sp = 0;

void push(int x);
int pop(void);
int peek(void);

int isFull(void);
int isEmpty(void);

int check(int x);

int main(){

    int preduvid = yylex();
    push(PROGRAM);

    while(!isEmpty()){
        switch(peek()){
            case PROGRAM:
                if(preduvid == ID || preduvid == PRINT){
                    pop();
                    push(PROGRAMP);
                    push(NAREDBA);
                }else{
                    fprintf(stderr, "sintaksna greska1\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case PROGRAMP:
                if (preduvid == ID || preduvid == PRINT){
                    pop();
                    push(PROGRAMP);
                    push(NAREDBA);
                }else if (preduvid == EOI){
                    pop();
                }else{
                    fprintf(stderr, "sintaksna greska2\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case NAREDBA:
                if (preduvid == ID){
                    pop();
                    push(TZ);
                    push(IZRAZ);
                    push(DODELA);
                    push(ID);
                }else if (preduvid == PRINT){
                    pop();
                    push(TZ);
                    push(IZRAZ);
                    push(PRINT);
                }else{
                    fprintf(stderr, "sintaksna greska3\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case IZRAZ:
                if (preduvid == OZ){
                    pop();
                    push(ZZ);
                    push(LISTA);
                    push(OZ);
                }else if (preduvid == BROJ){
                    pop();
                    push(BROJ);
                    push(TT);
                    push(BROJ);
                }else if (preduvid == ID){
                    pop();
                    push(ID);
                }else{
                    fprintf(stderr, "sintaksna greska4\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case LISTA:
                if(preduvid == BROJ){
                    pop();
                    push(LISTAP);
                    push(BROJ);
                }else{
                    fprintf(stderr, "sintaksna greska5\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case LISTAP:
                if(preduvid == ZAREZ){
                    pop();
                    push(LISTAP);
                    push(BROJ);
                    push(ZAREZ);
                }else if(preduvid == ZZ){
                    pop();
                }else{
                    fprintf(stderr, "sintaksna greska6\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                if (check(preduvid)){
                    pop();
                    preduvid = yylex();
                }else{
                    fprintf(stderr, "sintaksna greska7\n");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }

    printf("Sve ok\n");
    exit(EXIT_SUCCESS);
}

void push(int x){
    if (isFull()){
        fprintf(stderr, "stek je pun\n");
        exit(EXIT_FAILURE);
    }
    stek[sp++]=x;
}
int pop(void){
    if (isEmpty()){
        fprintf(stderr, "stek je prazan\n");
        exit(EXIT_FAILURE);
    }
    return stek[--sp];
}
int peek(void){
    if (isEmpty()){
        fprintf(stderr, "stek je prazan\n");
        exit(EXIT_FAILURE);
    }
    return stek[sp-1];
}

int isFull(void){
    return sp == MAX;
}
int isEmpty(void){
    return sp == 0;
}

int check(int x){
    return peek() == x;
}
