#include <stdio.h>
#include "PQInterface.h"
#include "sorting.h"
void PriorityQueueSort(SortingArray A, int maximum)
{
    int i;
    PriorityQueue PQ;
    for (i=0; i<10; ++i){
      A[i]=SquareOf(3*i-13);
      printf("%d ",A[i]);
    }
    printf("\n");

    Initialize(&PQ);
    for (i=0; i<MAXCOUNT; ++i) Insert(A[i], &PQ);
    for (i=MAXCOUNT-1; i>=0; --i) A[i]=Remove(&PQ);
    for (i=0; i<10; ++i) {
      printf("%d ",A[i]);
    }
    printf("\n");
}

int SquareOf(int x)
{
  return x*x;
}