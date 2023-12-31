#ifndef TOKENI_H
#define TOKENI_H

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, usrMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "Sintaksna greska: %s\n", usrMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

/*definicija tokena */

#define EOI (0)
#define BROJ (1)
#define PLUS (2)
#define PUTA (3)
#define OZ (4)
#define ZZ (5)

/* definicija stanja - neterminala */

#define E (100)
#define EP (101)
#define T (102)
#define TP (103)
#define F (104)

#endif
