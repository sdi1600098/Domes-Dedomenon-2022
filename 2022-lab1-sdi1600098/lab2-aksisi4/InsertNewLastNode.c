#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Prototypes.h"

void InsertNewLastNode(char *A, NodeType **L)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Airport, A);
    N->Link=NULL;

    if (*L == NULL) {
        *L=N;
    } else {
        P=*L;
        while (P->Link != NULL) P=P->Link;
        P->Link=N;
    }

}