#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Actions.h"
int main(void){

    NodeType *L;
    int Count;
    int a, e;
    L=NULL;
    e = IsEmpty(&L);
    Print(L);
    Push(1821, &L);
    Enqueue(1998, &L);
    printf("%d\n", SizeOf(&L));
    Enqueue(2022, &L);
    printf("%d\n", SizeOf(&L));
    Print(L);
    a = Dequeue(&L);
    Print(L);
    a = Pop(&L);
    Print(L);
    e = IsEmpty(&L);
    printf("%d\n", SizeOf(&L));
}