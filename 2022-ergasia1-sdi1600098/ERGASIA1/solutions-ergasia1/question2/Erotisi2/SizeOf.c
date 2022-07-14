#include <stdio.h>
#include <stdlib.h>
#include "Actions.h"

int SizeOf(NodeType **L){
    NodeType *CurrentNode;
    int count = 0;
    if (*L != NULL) {
        if ((*L)->Link == NULL){
            count++;
        }
        else{
            CurrentNode=(*L)->Link;
            count++;
            while (CurrentNode->Link != NULL){
                CurrentNode=CurrentNode->Link;
                count++;
            }
        }
    }
    return count;
}