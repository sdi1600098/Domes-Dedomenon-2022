#include <stdio.h>
#include <stdlib.h>
#include "GraphT.h"
#include "Actions.h"

int main(void){
    int i = 0;
    signed int source = -1, dest = -1;
    int array[100];
    FILE* fp;
    Graph* Graph1;
    fp  = fopen("eisodos.txt", "r");
    while(fscanf(fp, "%d", &array[i]) != EOF) {
        if(array[i] < 0){
            array[i] = abs(array[i]);
        }
        if(i == 0)
            Graph1 = Initialize(array[i]);
        else if(source == -1)
            source = array[i];
        else{
            dest = array[i];
            InsertEdge(Graph1, source, dest);
            source = -1;
            dest = -1;
        }
        //printf("%d ", array[i]);
        i++;
    }
    ShowGraph(Graph1);
    SimplePathCheck(Graph1, 0, 5);
}