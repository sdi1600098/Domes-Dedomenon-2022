#include <stdio.h>
#include <stdlib.h>
#include "GraphT.h"
#include "Actions.h"

int main(void){
    int i = 0;
    signed int source = -1, dest = -1, weight = -1;
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
        else if(dest == -1){
            dest = array[i];
        }
        else{
            weight = array[i];
            InsertEdge(Graph1, source, dest, weight);
            source = -1;
            dest = -1;
            weight = -1;
        }
        //printf("%d ", array[i]);
        i++;
    }
    ShowGraph(Graph1);
    //MinimumSpanningTree(Graph1);
}