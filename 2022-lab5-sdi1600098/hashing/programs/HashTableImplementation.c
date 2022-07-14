/* This code is from the book "Data Structures, Algorithms and Software Principles in C" */
/* by Thomas A. Standish */

/* This is the file HashTableImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include "HashTableInterface.h"


int h(KeyType K)
{
  return K % TABLESIZE;
}


/* Hash function good for strings
int h(KeyType K)
{
  int h=0, a=127;
  for (; *K!='\0'; K++)
    h=(a*h + *K) % TABLESIZE;
  return h;
}

*/

int p(KeyType K)
{
  if(K/TABLESIZE > 1){
    return K/TABLESIZE;
  }
  return 1;
}

void Initialize(Table T) {
   int i;

   for (i=0; i<TABLESIZE; i++)
      T[i].Key=EmptyKey;
}

int HashInsert(Table T, KeyType K, InfoType I) {
   int i;
   int ProbeDecrement;

   i=h(K);
   ProbeDecrement=p(K);

   while (T[i].Key != EmptyKey){
      i-=ProbeDecrement;
      if (i<0)
        i+=TABLESIZE;
    }
    T[i].Key=K;
    T[i].Info=I;
    return i;
}


int HashSearch(Table T, KeyType K) {
   int i;
   int ProbeDecrement;
   KeyType ProbeKey;

   /*Initializations */
   i=h(K);
   ProbeDecrement=p(K);
   ProbeKey=T[i].Key;

   /* Search loop */
   while ((K!=ProbeKey) && (ProbeKey!=EmptyKey)){
      i-=ProbeDecrement;
      if (i<0)
         i+=TABLESIZE;
      ProbeKey=T[i].Key;
   }

   /* Determine success or failure */
   if (ProbeKey==EmptyKey)
      return -1;
   else
      return i;

}

void Print(Table T){
  int i;
  for(i=0;i<TABLESIZE;++i){
      if(T[i].Key == EmptyKey){
        printf("Empty element in position %d\n", i);
      }else{
        printf("Element in position %d with key \"%d\"\n",i,T[i].Key);
      }
    }
}
