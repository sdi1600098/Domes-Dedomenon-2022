#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Prototypes.h"

void InsertNewFirstNode (NodeType **L)
{
   NodeType *N;
   N=(NodeType *)malloc(sizeof(NodeType));
   strcpy(N->Airport,"ATH");
   N->Link=*L;
   *L = N;
}