#include <stdio.h>
#include "Subsum.h"
#define Sum 0                                                                       //Given Sum

signed int Numbz[] = {3, 1, -4, 7};                                                 //Set of numbers that we are trying to find a subset of.

int main(){
    int n = sizeof(Numbz) / sizeof(Numbz[0]);                                       //Size of given set
    signed int CurrSum = 0;                                                         
    if(SubSum(Numbz, n, Sum, CurrSum) == 1)                                         //If recursive function is true then there is a subset.
        printf("There is a subset with sum equal to %d\n", Sum);
    else
        printf("There isn't a subset with sum equal to %d\n", Sum);
    
    return 0;
}