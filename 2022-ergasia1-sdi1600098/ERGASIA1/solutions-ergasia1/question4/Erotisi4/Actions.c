#include <stdlib.h>
#include <stdio.h>
#include "Actions.h"

void Create(link *last){                                //Οι παρακάτω ενέργειες αναλύονται στην Ερώτηση 3.
    (*last) = NULL;
}

void Add(link *last, link *x, int *Count){
    *Count += 1;
    (*x) = malloc(sizeof **x);

    if(*last == NULL){
    
        (*x)->item = 1;
        (*x)->next = *x;
        (*last) = (*x);
        
    }
    else {
        //(*x) = ((*x)->next = malloc(sizeof **x));
        (*x)->item = *Count;
        (*x)->next = (*last)->next;
        (*last)->next = (*x);
        (*last) = (*x);
    }
}

link Remove(link *dromeas, link *x){
    link temp = (*x)->next;
    (*x)->next = (*x)->next->next;
    return temp;
}

void Advance(link *dromeas, link *x){
    (*x) = (*x)->next;
    (*dromeas) = (*x);
}