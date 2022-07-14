#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Prototypes.h"

void PrintList(NodeType *L)
{
    NodeType *N;

    printf("(");
    N=L;
    while(N != NULL) {
        printf("%s", N->Airport);
        N=N->Link;
        if (N!=NULL) printf(",");
    }
    printf(")\n");
}