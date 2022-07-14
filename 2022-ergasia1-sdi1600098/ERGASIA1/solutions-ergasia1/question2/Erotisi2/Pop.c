#include <stdlib.h>
#include <stdio.h>
#include "Actions.h"

int Pop(NodeType **L) { 
    NodeType *CurrentNode;
    int arithmos;
    CurrentNode=*L;
    arithmos = CurrentNode->Item;
    *L = (*L)->Link;
    free(CurrentNode);
    return arithmos;
  }