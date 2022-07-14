#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Actions.h"

int Dequeue(NodeType **L)
{
    NodeType *PreviousNode, *CurrentNode;
    int arithmos;
    if (*L != NULL) {
        if ((*L)->Link == NULL){
        free(*L);
        *L=NULL;
        } 
        else {
        PreviousNode=*L;
        CurrentNode=(*L)->Link;
        while (CurrentNode->Link != NULL){
            PreviousNode=CurrentNode;
            CurrentNode=CurrentNode->Link;
        }
        PreviousNode->Link=NULL;
        arithmos = CurrentNode->Item;
        free(CurrentNode);
        }
    }
    return arithmos;
}