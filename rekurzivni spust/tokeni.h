#ifndef TOKENI_H
#define TOKENI_H

#include <stdio.h>
#include <stdlib.h>

#define check_error(userMsg)\
    do {\
        fprintf(stderr, "Sintaksna greska: %s\n", userMsg);\
        exit(EXIT_FAILURE);\
    }while(0)

#define EOI  (0)
#define BROJ (1)
#define PLUS (2)
#define PUTA (3)
#define OZ   (4)
#define ZZ   (5)

#endif
