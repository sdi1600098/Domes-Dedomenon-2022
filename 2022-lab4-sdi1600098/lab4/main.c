#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

void main(int argc, char *argv[]){ 
    int N, maxN = atoi(argv[1]);
    Item temp = malloc(sizeof temp);
    int test;
    STinit(maxN);
    for (N = 0; N < maxN; N++){
        temp = ITEMscan(&test);
        //printf("%d\n",test);
        //printf("%s\n",temp->onoma);
        //printf("%s\n",temp->epitheto);
        STinsert(temp, test);  
    }
    int x = 0;
    do{
        printf("Pliktrologiste arnitiko arithm gia eksodo, allios eisagete AM: ");
        scanf("%d", &x);
        temp = STsearch(x);
        if(temp == NULL){
            printf("den uparxei atomo me auto ton AM sti lista.\n");
        }
        else
            printf("%s %s\n",temp->onoma, temp->epitheto);
    } while(x > 0);

    NaturalOrder();

    Item maxim = malloc(sizeof maxim);
    maxim = FindMax();
    Item minim = malloc(sizeof maxim);
    minim = FindMin();
    printf("atomo me to megisto AM: %s %s\natomo me ton elaxisto AM: %s %s\n", maxim->onoma, maxim->epitheto, minim->onoma, minim->epitheto);
}