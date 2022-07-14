#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Prototypes.h"

void InsertNewSecondNode (NodeType **L)
{
    NodeType *N;
    N=(NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Airport,"BRU");
    N->Link=(*L)->Link;
    (*L)->Link=N;
}