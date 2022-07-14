#include <stdio.h>
#include <stdlib.h>
#include "StackInterface.h"

void InitializeStackOp(OpStack *S){
    S->OpCount=0;
}

int EmptyOp(OpStack *S){
    return (S->OpCount == 0);
}

int FullOp(OpStack *S){
return(S->OpCount == 100);
}

void PopOp(OpStack *S, ItemTypeOp *X){
    if (S->OpCount ==0){
        //printf("attempt to pop the empty stack");
    }   
    else{
        --(S->OpCount);
        *X=S->OpItems[S->OpCount];
    }
}

void PushOp(ItemTypeOp X, OpStack *S){
    if (S->OpCount == 100){
        //printf("attempt to push new item on a full stack");
    } else {
        S->OpItems[S->OpCount]=X;
        ++(S->OpCount);
    }
}

//////////////////////////////////

void InitializeStackNum(NumStack *S){
    S->NumCount=0;
}

int EmptyNum(NumStack *S){
    return (S->NumCount == 0);
}

int FullNum(NumStack *S){
return(S->NumCount == 100);
}

void PopNum(NumStack *S, ItemTypeNum *X){
    if (S->NumCount ==0){
        //printf("attempt to pop the empty stack");
    }   
    else{
        --(S->NumCount);
        *X=S->NumItems[S->NumCount];
    }
}

void PushNum(ItemTypeNum X, NumStack *S){
    if (S->NumCount == 100){
        //printf("attempt to push new item on a full stack");
    } else {
        S->NumItems[S->NumCount]=X;
        ++(S->NumCount);
    }
}