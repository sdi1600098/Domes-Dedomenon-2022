/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"
void main(int argc, char *argv[])
 { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    STinit(maxN);
    for (N = 0; N < maxN; N++)
      {
        if (sw) v = ITEMrand();
        else if (ITEMscan(&v) == EOF) break;
        if (STsearch(v) != NULLitem) continue;
        key(item) = v;
        printf("Inserting item %d\n", item);
        //STinsert1(item, N+1);
        STinsert(item);
      }
    //STinsertT(10);
    //N++;
    /* checking the behaviour of sorting operation */
    printf("The keys in sorted order are: ");
    STsort(ITEMshow); printf("\n");
    
    printf("%d keys\n", N);
    printf("%d distinct keys\n", STcount());
    
    /* checking the behaviour of select operation by selecting the item with the 4th smallest key */
    Item i=STselect(3);
    printf("The item with the fourth smallest key is %10d\n", i);
    /* checking the behaviour of delete operation by deleting items with keys 1 and 2*/
    STdelete(1);
    STdelete(2);
    printf("After the two deletions the keys in sorted order are: ");
    STsort(ITEMshow); printf("\n");
    //////////////
    printf("Preorder:\n");
    STpreorder(ITEMshow);
    printf("Inorder:\n");
    STinorder(ITEMshow);
    printf("Postorder:\n");
    STpostorder(ITEMshow);
    ////////////
    int min, max;
    min = STmin(ITEMshow);
    max = STmax(ITEMshow);
    printf("minimum key number : %d\nmaximum key number : %d\n", min, max);
 }
