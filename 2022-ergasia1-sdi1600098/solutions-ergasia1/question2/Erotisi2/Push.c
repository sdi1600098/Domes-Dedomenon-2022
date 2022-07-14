#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Actions.h"

void Push (int number, NodeType **L)
{
   NodeType *N;
   N=(NodeType *)malloc(sizeof(NodeType));
   N->Item = number;
   N->Link=*L;
   *L = N;
   
}