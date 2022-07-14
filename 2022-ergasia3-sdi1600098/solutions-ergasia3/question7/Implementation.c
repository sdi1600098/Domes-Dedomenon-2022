#include <stdio.h>
#include <stdlib.h>
#include "DataType.h"
#define TABLESIZE 10

static Item HashTable[TABLESIZE];
void CreateTable(void){
    int i;
    for(i = 0 ; i < TABLESIZE ; i++){
        HashTable[i].key = -1;
        //HashTable[i].data = '-';
    }
    printf("A %d slot Hash Table has been created.\n", TABLESIZE);
    return;
}

void Insert(int key){
    int index = key % TABLESIZE;
    int i;
    if(HashTable[index].key == -1){
        HashTable[index].key = key;
        printf("Stored data(%d) in HashTable[%d]\n", key, index);
        return;
    }
    else{
        printf("There is already data in this slot, searching for next available slot...\n");
        for(i = index ; i > -1 ; i--){
            if(HashTable[i].key != -1){

            }
            else{
                HashTable[i].key = key;
                printf("Stored data(%d) in Array[%d]\n", key, i);
                return;
            }
        }
        for(i = index ; i < TABLESIZE ; i++){
            if(HashTable[i].key != -1){

            }
            else{
                HashTable[i].key = key;
                printf("Stored data(%d) in HashTable[%d]\n", key, i);
                return;
            }
        }
    }
    printf("HashTable is full, cannot insert data!\n");
    return;
}

void Search(int key){
    for(int i = 0 ; i < TABLESIZE ; i++){
        if(HashTable[i].key == key){
            printf("Key(%d) exists in HashTable[%d]\n", key, i);
            return;
        }
    }
    printf("Key(%d) does not exist in HashTable\n", key);
    return;
}
