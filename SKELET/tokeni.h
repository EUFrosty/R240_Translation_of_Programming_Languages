#ifndef TOKENI_H
#define TOKENI_H

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, usrMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "Sintaksna greska: %s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

/*definicija tokena */



/* definicija stanja - neterminala */



#endif
