#include <stdio.h>

int SubSum(signed int SetOfNumbers[], int n, signed int SumWeWant, signed int CurrentSum){

    if(CurrentSum + SetOfNumbers[n-1] == SumWeWant){                            //if the last unchecked number + the current sum equals the sum we are looking for, return true.
        return 1;
    }
    if(n == 0){                                                                 //if there are no unchecked numbers left then return false  
        return 0;                                                               //In this implementation numbers are checked from last to first.//
    }                                                                           //If we want to check from first to last, we change to n >= nmax, and SetOfNumbers[n+1]//

    if(SetOfNumbers[n-1] + CurrentSum != SumWeWant){
        return SubSum(SetOfNumbers, n-1, SumWeWant, CurrentSum + SetOfNumbers[n-1]) || SubSum(SetOfNumbers, n-1, SumWeWant, CurrentSum);
    }
    /*This 'if' is optional. Call the function again once for the subset including the last checked number and once for the subset not including the last checked number.
}