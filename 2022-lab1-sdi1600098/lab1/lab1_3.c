#include <stdio.h>
#include <stdlib.h>

void P(void)

{

int *A, *B;

A=(int *)malloc(sizeof(int));

B=(int *)malloc(sizeof(int));

*A=19;

*B=5;

*A=*B;

*B=7;

printf("%d\n", *A);

}

int main(void){
    P();
    return 0;
}