#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Actions.h"

void Enqueue(int number, NodeType **L)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    N->Item = number;
    N->Link=NULL;

    if (*L == NULL) {
        *L=N;
    } else {
        P=*L;
        while (P->Link != NULL) P=P->Link;
        P->Link=N;
    }
}