#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Prototypes.h"

void DeleteLastNode(NodeType **L)
{
    NodeType *PreviousNode, *CurrentNode;

    if (*L != NULL) {
        if ((*L)->Link == NULL){
        free(*L);
        *L=NULL;
        } else {
        PreviousNode=*L;
        CurrentNode=(*L)->Link;
        while (CurrentNode->Link != NULL){
            PreviousNode=CurrentNode;
            CurrentNode=CurrentNode->Link;
        }
        PreviousNode->Link=NULL;
        free(CurrentNode);
        }
    }
}