#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StackInterface.h"

int Evaluation(NumStack *Numbers, OpStack *Operators, char PostfixString[100]){
    InitializeStackNum(Numbers);
    InitializeStackOp(Operators);
    int i = 0;
    while(PostfixString[i] != '\0'){
        if (isdigit(PostfixString[i])){                                             //If the character is a number then it is pushed in the number stack            
            PushNum(atoi(&PostfixString[i]), Numbers);
        }
        else if(PostfixString[i] == '+' || PostfixString[i] == '-' || PostfixString[i] == '*'){
            switch(PostfixString[i]){
                case '+':
                    if(Operators->OpItems[Operators->OpCount-1] != '*'){
                        PushOp(PostfixString[i], Operators);
                    }
                    else{
                        while(Operators->OpItems[Operators->OpCount-1] == '*' && EmptyOp(Operators) == 0){
                            Process(Numbers, Operators);
                        }
                        PushOp(PostfixString[i], Operators);
                    }
                    break;
                case '-': 
                    if(Operators->OpItems[Operators->OpCount-1] != '*'){
                        //printf("%c  lol\n",Operators->OpItems[Operators->OpCount]);
                        PushOp(PostfixString[i], Operators);
                    }
                    else{
                        while(Operators->OpItems[Operators->OpCount-1] == '*' && EmptyOp(Operators) == 0){
                            printf("this is the previous :%c\n", Operators->OpItems[Operators->OpCount-1]);
                            Process(Numbers, Operators);
                        }
                        PushOp(PostfixString[i], Operators);
                    }
                    break;
                case '*': PushOp(PostfixString[i], Operators);
                //printf("lathos = %c, swsto = %c\n",Operators->OpItems[Operators->OpCount], Operators->OpItems[Operators->OpCount-1]);
            }
        }
        else if(PostfixString[i] == '(' || PostfixString[i] == ')'){
            //PushOp(PostfixString[i], Operators);
            switch(PostfixString[i]){
                case '(': PushOp(PostfixString[i], Operators);
                    break;
                case ')': 
                    while(Operators->OpItems[Operators->OpCount-1] != '('){
                        Process(Numbers, Operators);
                    }
            }
        }
        i++;
    }
    while(EmptyOp(Operators) == 0){
        Process(Numbers, Operators);
    }
    ItemTypeNum result;
    PopNum(Numbers, &result);
    printf("the infix is equal to %d\n", Numbers->NumItems[Numbers->NumCount]);
}

void Process(NumStack *Numbers, OpStack *Operators){
    ItemTypeNum A, B;
    ItemTypeOp C;
    PopNum(Numbers, &A);
    PopNum(Numbers, &B);
    PopOp(Operators, &C);
    switch (C) {
        case '+': PushNum((A+B), Numbers);
            break;
        case '-': PushNum((B-A), Numbers);
            break;
        case '*': PushNum((A*B), Numbers);
            break;
    }

}