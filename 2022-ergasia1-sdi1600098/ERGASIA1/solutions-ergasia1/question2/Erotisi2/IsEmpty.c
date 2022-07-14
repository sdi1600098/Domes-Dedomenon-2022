#include <stdio.h>
#include <stdlib.h>
#include "Actions.h"

int IsEmpty(NodeType **L){
    if(*L == NULL){
        return 0;
    }
    else return 1;
}