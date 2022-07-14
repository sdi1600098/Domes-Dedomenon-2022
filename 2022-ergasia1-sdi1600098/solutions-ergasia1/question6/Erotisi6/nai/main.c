#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StackInterface.h"
char PostfixString[100];
NumStack Numbers;
OpStack Operators;

int main(){
    printf("Give input postfix string without blanks:");
    scanf("%s", PostfixString);
    Evaluation(&Numbers, &Operators, PostfixString);
    
    return 0;
}