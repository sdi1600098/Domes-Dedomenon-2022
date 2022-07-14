#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

Item ITEMscan(int *x)
{
    Item onomateponimo = malloc(sizeof onomateponimo);
    char stoixeia[50];
    scanf(" %[^\n]", stoixeia);
    int i=0;
   
    char * token = strtok(stoixeia, " ");
    char* Plirofories[3];
    Plirofories[0] = malloc(20);
    Plirofories[1] = malloc(20);
    Plirofories[2] = malloc(20);

    while( token != NULL ) {
        strcpy(Plirofories[i],token);
       // printf( " %s\n", Plirofories[i] );
        token = strtok(NULL, " ");
        i++;

    }

    *x = atoi(Plirofories[0]);
    strcpy (onomateponimo->onoma, Plirofories[1]);
    strcpy(onomateponimo->epitheto, Plirofories[2]);
    return onomateponimo;
}


