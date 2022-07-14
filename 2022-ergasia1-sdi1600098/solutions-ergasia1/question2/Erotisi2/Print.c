#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Actions.h"

void Print(NodeType *L)
{
    NodeType *N;

    printf("(");
    N=L;
    while(N != NULL) {
        printf("%d", N->Item);
        N=N->Link;
        if (N!=NULL) printf(",");
    }
    printf(")\n");
}