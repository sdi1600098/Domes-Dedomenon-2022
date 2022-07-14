#include <stdio.h>
#include <stdlib.h>
#include "Implementation.h"
char PairString[1000];
int main(int argv, char *argc[]){
    int N = atoi(argc[1]);
    int i = 0, j;
    //////////////////
    int **Tasks = malloc((N+1) *sizeof (int*));             // 1)
    for(i = 0 ; i < N+1 ; i++){
        Tasks[i] = malloc(N *sizeof (int));
    }
    ///////////////////////
    printf("give pairs: ");
    scanf("%s", PairString);                                // 2)
    FillTheArray(PairString, Tasks, N);
    /////////////
}