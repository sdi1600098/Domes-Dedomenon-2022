#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#define M 100

// Program 16.1 B+-tree definitions and initialization

typedef struct STnode *link;
/////////////////
typedef struct
{
  Key key;
  union
  {
    link next;
    Item item;
  } ref;
} entry;
////////////////
struct STnode
{
  entry b[M];
  int m;
};
///////////////

static link head;
static int H, N;
link split(link x);
link NEW()
{
  link x = malloc(sizeof *x);
  x->m = 0;
  return x;
}
void STinit(int maxN)
{
  head = NEW();
  H = 0;
  N = 0;
}

// Program 16.2 B+-tree search

Item searchR(link h, Key v, int H)
{
  int j;
  if (H == 0)
    for (j = 0; j < h->m; j++)
      if (eq(v, h->b[j].key))
        return h->b[j].ref.item;
  if (H != 0)
    for (j = 0; j < h->m; j++)
      if ((j + 1 == h->m) || less(v, h->b[j + 1].key))
        return searchR(h->b[j].ref.next, v, H - 1);
  return NULL;
}
Item STsearch(Key v)
{
  return searchR(head, v, H);
}

// Program 16.3 B-tree insertion

link insertR(link h, Item item, int AM, int H)
{
  int i, j;
  Key v = key(AM);
  entry x;
  link u;
  x.key = v;
  x.ref.item = item;
  if (H == 0)
    for (j = 0; j < h->m; j++)
      if (less(v, h->b[j].key))
        break;
  if (H != 0)
    for (j = 0; j < h->m; j++)
      if ((j + 1 == h->m) || less(v, h->b[j + 1].key))
      {
        u = insertR(h->b[j++].ref.next, item, AM, H - 1);
        if (u == NULL)
          return NULL;
        x.key = u->b[0].key;
        x.ref.next = u;
        break;
      }
  for (i = (h->m)++; i > j; i--)
    h->b[i] = h->b[i - 1];
  h->b[j] = x;
  if (h->m < M)
    return NULL;
  else
    return split(h);
}
void STinsert(Item item, int AM)
{
  link t, u = insertR(head, item, AM, H);
  if (u == NULL)
    return;
  t = NEW();
  t->m = 2;
  t->b[0].key = head->b[0].key;
  t->b[0].ref.next = head;
  t->b[1].key = u->b[0].key;
  t->b[1].ref.next = u;
  head = t;
  H++;
}

link split(link h)
{
  int j;
  link t = NEW();
  for (j = 0; j < M / 2; j++)
    t->b[j] = h->b[M / 2 + j];
  h->m = M / 2;
  t->m = M / 2;
  return t;
}
void PrintInOrder(entry* node){
  if(node == NULL)
    return;
  //int temp = node->m;
  /*for (int j = 0; j < temp; j++){
    if(node == NULL)
    return;
    printf("AM: %d, Onoma: %s, Epitheto: %s\n",node->b[j].key, node->b[j].ref.item->onoma, node->b[j].ref.item->epitheto);
  }*/
  if(temp-1 >= 0)
    PrintInOrder(node->b[temp-1].ref.next);
  printf("AM: %d, Onoma: %s, Epitheto: %s\n",node->b[temp].key, node->b[temp].ref.item->onoma, node->b[temp].ref.item->epitheto);
  if(temp+1 <= head->m)
    PrintInOrder(node->b[temp+1].ref.next);
  
}
void NaturalOrder(){
  PrintInOrder(&head->b[0]);
}

Item FindMax(){
  int maxim = head->m;
  return head->b[maxim - 1].ref.item;
}

Item FindMin(){
  return head->b[0].ref.item;
}