/*Gramatika:                        Skupovi izbora:
 *
 * E -> T EP                        {OZ, BROJ}
 * EP -> + T EP                     {PLUS}
 *      eps                         {EOI, ZZ}
 * T -> F TP                        {OZ, BROJ}
 * TP -> * F TP                     {PUTA}
 *      eps                         {PLUS, EOI, ZZ}
 * F -> ( E )                       {OZ}
 *      BROJ                        {BROJ}
 */

#include <stdio.h>
#include <stdlib.h>

#include "tokeni.h"

#define MAX_DEPTH (256)

extern int yylex();

int stek[MAX_DEPTH];
int sp = 0;

int pop(void);
void push(int x);
int peek(void);
int empty(void);
int check(int x);

int main(int argc, char** argv){

    int preduvid = yylex();
    push(E);

    while(!empty()) {
        switch (peek()){

            case E:
                if(preduvid == OZ || preduvid == BROJ){
                    pop();
                    push(EP);
                    push(T);
                }else{
                    check_error(0, "greska");
                }
                break;
            case EP:
                if(preduvid == PLUS){
                    pop();
                    push(EP);
                    push(T);
                    push(PLUS);
                }else if(preduvid == EOI || preduvid == ZZ){
                    pop();
                }else{
                    check_error(0, "greska");
                }
                break;
            case T:
                if(preduvid == OZ || preduvid == BROJ){
                    pop();
                    push(TP);
                    push(F);
                }else{
                    check_error(0, "greska");
                }
                break;
            case TP:
                if(preduvid == PUTA){
                    pop();
                    push(TP);
                    push(F);
                    push(PUTA);
                }else if(preduvid == EOI || preduvid == ZZ || preduvid == PLUS){
                    pop();
                }else{
                    check_error(0, "greska");
                }
                break;
            case F:
                if(preduvid == OZ){
                    pop();
                    push(ZZ);
                    push(E);
                    push(OZ);
                }else if(preduvid == BROJ){
                    pop();
                    push(BROJ);
                }else{
                    check_error(0, "greska");
                }
                break;
            default:
                if(check(preduvid)) {
                    pop();
                    preduvid=yylex();
                }else{
                    check_error(0, "greska");
                }
                break;
        }
    }

    printf("sve OK\n");
    exit(EXIT_SUCCESS);
}

int pop(void){
    check_error(sp > 0, "prazan stek");
    return stek[ --sp ];
}

void push(int x){
    check_error(sp < MAX_DEPTH, "max dubina");
    stek[ sp++ ] = x;
    return;
}

int peek(void){
    check_error(sp > 0, "prazan stek");
    return stek[ sp-1 ];
}

int empty(void){

    return sp == 0;
}

int check(int x){
    check_error(sp > 0, "prazan stek");
    return x == stek[ sp-1 ];

}







