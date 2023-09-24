/* Gramatika :
 *
 * E - > T EP                   {OZ, BROJ}
 * EP - > + T EP                {PLUS}
 *      eps                     {EOI, ZZ}
 * T - > F TP                   {OZ, BROJ}
 * TP - > * F TP                {PUTA}
 *      eps                     {PLUS, EOI, ZZ}
 * F - > ( E )                  {OZ}
 *      BROJ                    {BROJ}
 */


#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"

#define DEBUG (1)

extern int yylex();

int preduvid = 0;

void E(void);
void EP(void);
void T(void);
void TP(void);
void F(void);

int main(){

    preduvid = yylex();

    E();

    if (preduvid == EOI) {
        printf("Sve ok. \n");
    }else{
        printf("Sintaksna greska. Visak tokena na ulazu. \n");
    }

    exit(EXIT_SUCCESS);
}



void E(void){
    if (preduvid == OZ || preduvid == BROJ){
#ifdef DEBUG
        printf(" E - > T EP\n");
#endif
        T();
        EP();
    }else{
        check_error("Sintaksna greska. Ocekivano OZ ili BROJ");
    }
}



void EP(void){
    if (preduvid == PLUS){
#ifdef DEBUG
        printf("EP - > + T EP\n");
#endif
        preduvid = yylex();
        T();
        EP();
    }else if(preduvid == EOI || preduvid == ZZ){
#ifdef DEBUG
        printf("EP - > eps\n");
#endif
        return;
    }else{
        check_error("Sintaksna greska. Ocekivano PLUS, EOI ili ZZ");
    }
}


void T(void){
    if (preduvid == OZ || preduvid == BROJ){
#ifdef DEBUG
        printf("T - > F TP\n");
#endif
        F();
        TP();
    }else{
        check_error("Sintaksna greska. Ocekivano OZ ili BROJ");
    }
}


void TP(void){
    if (preduvid == PUTA){
#ifdef DEBUG
        printf("TP - > * F TP\n");
#endif
        preduvid = yylex();
        F();
        TP();
    }else if( preduvid == PLUS || preduvid == EOI || preduvid == ZZ){
#ifdef DEBUG
        printf("TP - > eps\n");
#endif
        return;
    }else{
        check_error("Sintaksna greska. Ocekivano PUTA, PLUS, EOI ili ZZ");
    }
}



void F(void){
    if (preduvid == OZ){
#ifdef DEBUG
        printf("F - > ( E )\n");
#endif
        preduvid = yylex();
        E();
        if (preduvid != ZZ){
            check_error("Sintaksna greska. Ocekivano ZZ");
        }
        preduvid = yylex();
    }else if (preduvid == BROJ){
#ifdef DEBUG
        printf("F - > BROJ \n");
#endif
        preduvid = yylex();
        return;
    }else{
        check_error("Sintaksna greska. Ocekivano OZ ili BROJ");
    }
}
