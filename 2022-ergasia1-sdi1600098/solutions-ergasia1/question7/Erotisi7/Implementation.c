#include <stdio.h>
#include <stdlib.h>

void FillTheArray(char *PairString, int **Tasks, int N){
    int i,j;                                                                        //EXECUTION EXPLAINED IN Explanation.pdf
    signed int Prerequisite = -1;
    signed int EachSecondTask = -1;
    i = 0;
    while(PairString[i] != '\0'){                                                   //3
        if(PairString[i] >= '0' && PairString[i] <= '9'){
            if(Prerequisite < 0){
                Prerequisite = PairString[i] -'0';
            }
            else{
                EachSecondTask = PairString[i] -'0';
                Tasks[EachSecondTask][Prerequisite] = 1;
                Tasks[N][EachSecondTask] += 1;
                Prerequisite = -1;
                EachSecondTask = -1;
            }
        }
        i++;
    }
    /*for(i = 0 ; i < N+1 ; i++){                     
        for(j = 0 ; j < N ; j++){
            printf("%d ",Tasks[i][j]);
        }
        printf("\n");
    }*/
    printf("\nTask Order: ");
    int finished = 0;
    int FirstTask = 1;
    int NextTaskFound = 1;
    while(finished != 1){                               // 4)
        for(j = 0 ; j < N ; j++){
            if(Tasks[N][j] == 0){
                Tasks[N][j] = N+1;
                if(FirstTask == 1){
                    printf("%d", j);
                    FirstTask = 0;
                }
                else{
                    printf(" -> %d", j);
                }
                for(i = 0 ; i < N ; i++){
                    if(Tasks[i][j] == 1){
                        Tasks[N][i] -= 1;
                    }
                }
            }
        }
        finished = 1;
        for(j = 0 ; j < N ; j++){                       // 5)
            if(Tasks[N][j] == 0){
                finished = 0;
                NextTaskFound = 1;
                break;
            }
            else if(Tasks[N][j] == N+1){
                continue;
            }
            else{
                finished == 0;
                NextTaskFound = 0;
            }
        }
    }
    printf("\n");
}