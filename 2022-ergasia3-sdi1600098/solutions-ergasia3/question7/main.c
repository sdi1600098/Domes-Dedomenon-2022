#include <stdio.h>
#include <stdlib.h>
#include "DataType.h"
#include "Actions.h"

int main(void){
    int input;
    int created = 0;
    while(1){
        printf("\n1. Create/Reset Hash Table\t2. Insert item in Hash Table\n3. Remove item from Hash Table\t4. Search item in Hash Table\n5. Exit\n\n");
        printf("Choose a command: ");
        scanf("%d", &input);
        if(input < 1 || input > 5)
            printf("Unknown command.\n");
        else if(input == 1){
            CreateTable();
            created = 1;
        }
        else if(input == 5){
            printf("Exiting...\n");
            return 0;
        }
        else{
            if(created == 0 )
                printf("Create a Hash Table first.\n");
            else if(input == 2){
                printf("Input Data value to be inserted: ");
                scanf("%d", &input);
                Insert(input);
            }
            else if(input == 3){
                printf("Not ready yet :)\n");
            }
            else if(input == 4){
                printf("Input Data value: ");
                scanf("%d", &input);
                Search(input);
            }
        }
    }
}