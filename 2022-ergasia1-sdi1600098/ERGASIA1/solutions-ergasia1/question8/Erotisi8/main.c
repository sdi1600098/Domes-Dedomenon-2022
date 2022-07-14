#include <stdio.h>
#include "PQInterface.h"
#include "sorting.h"

//typedef PQItem SortingArray[MAXCOUNT];
/* Note: MAXCOUNT is 10 */

int main(void)
{
    int i; SortingArray A;

    PriorityQueueSort(A, MAXCOUNT);
}