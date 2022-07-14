/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct STnode* nlink;
struct STnode { Item item; nlink l, r; int N; };

static nlink head, z, root;
nlink NEW(Item item, nlink l, nlink r, int N)
  { nlink x = malloc(sizeof *x);
    x->item = item; 
    x->l = l; 
    x->r = r; 
    x->N = N;
    return x;
  }
/* initialization operation */  
void STinit(){ 
  head = (z = NEW(NULLitem, NULL, NULL, 0)); 
  root = NULL;  
}
/*nlink insert1(nlink root, Item item, int N){
  nlink *pp = &root;
  while (*pp != NULL) {
    if (item > (*pp)->item)
      pp = &(*pp)->r;
    else
      pp = &(*pp)->l;
  }
  *pp = NEW(item, NULL, NULL, N);
  return root;
}
void STinsert1(Item item, int N){
  head = insert1(head, item, N);
}*/
void insertI(nlink root, Item item, int N){
  nlink x = root;
  nlink y = NULL;
  nlink newnode = NEW(item, NULL, NULL, N);
  while(x != NULL){
    //printf("opalakia");
    y = x;
    if (item < x->item){
      x = x->l;
      //printf("1");
    }
    else{
      x = x->r;
      //printf("2");
    }
  }
  if (y == NULL){
    y = newnode;
    root = y;
  }
  else if (item < y->item)
    y->l = newnode;
  else
    y->r = newnode;
  (head->N)++;
}
void STinsert1(Item item, int N){
  insertI(root, item, 1);
}

/* count operation */
int STcount() { return head->N; }

/* search operation */
Item searchR(nlink h, Key v)
  { Key t = key(h->item);
    if (h == z) return NULLitem;
    if eq(v, t) return h->item;
    if less(v, t) return searchR(h->l, v);
      else return searchR(h->r, v);
  }
  
Item STsearch(Key v)
  { return searchR(head, v); }

/* recursive insert operation */
nlink insertR(nlink h, Item item)
  { Key v = key(item), t = key(h->item);
    if (h == z) return NEW(item, z, z, 1);
    if less(v, t)
      h->l = insertR(h->l, item);
    else h->r = insertR(h->r, item);
    (h->N)++; return h;
  }
  
void STinsert(Item item)
  { head = insertR(head, item); }

/* rotation auxiliary functions */
nlink rotR(nlink h)
  { nlink x = h->l; 
    h->l = x->r; 
    x->r = h;
   
    return x; 
  }

nlink rotL(nlink h)
  { nlink x = h->r;
    h->r = x->l; 
    x->l = h;
    
    return x; 
  }

// Insertion at the root, commented out, note that the counters at each node are not updated
nlink insertT(nlink h, Item item)
  { Key v = key(item);
    if (h == z){
      //(h->N)++;
      return NEW(item, z, z, 1);
    }
    if (less(v, key(h->item)))
      { h->l = insertT(h->l, item); h = rotR(h); }
    else
      { h->r = insertT(h->r, item); h = rotL(h); }
    (h->N)++;//
    return h;
  }

void STinsertT(Item item)
  { head = insertT(head, item); }



/* sort operation */
void sortR(nlink h, void (*visit)(Item))
  {
    if (h == z) return;
    sortR(h->l, visit);
    visit(h->item);
    sortR(h->r, visit);
  }
  
void STsort(void (*visit)(Item))
  { sortR(head, visit); }

/* select operation */
Item selectR(nlink h, int k)
  { 
    int t;
    if (h == z) return NULLitem;
    t = (h->l == z) ? 0 : h->l->N;
    if (t > k) return selectR(h->l, k);
    if (t < k) return selectR(h->r, k-t-1);
    return h->item;
  }

Item STselect(int k)  
  { return selectR(head, k); }

/* partition auxiliary function */
nlink partR(nlink h, int k)
  { int t = h->l->N;
    if (t > k )
      { h->l = partR(h->l, k); h = rotR(h); }
    if (t < k )
      { h->r = partR(h->r, k-t-1); h = rotL(h); }
    return h;
  }

/* recursive deletion operation */
nlink joinLR(nlink a, nlink b)
  {
    if (b == z) return a;
    b = partR(b, 0); b->l = a;
    return b;
  }
  
nlink deleteR(nlink h, Key v)
  { nlink x; Key t = key(h->item);
    if (h == z) return z;
    if (less(v, t)) h->l = deleteR(h->l, v);
    if (less(t, v)) h->r = deleteR(h->r, v);
    if (eq(v, t))
      { x = h; h = joinLR(h->l, h->r); free(x); }
    return h;
  }
  
void STdelete(Key v)
  { head = deleteR(head, v); }

////////////////////////////////////

void preorderR(nlink h, void (*Visit)(Item x)){
  if (h) {
    if(h->item >= 0){
      printf("%d\n",h->item);
    }
    preorderR(h->l, Visit);
    preorderR(h->r, Visit);
  }
}
void STpreorder(void (*Visit)(Item x)){
  preorderR(head, Visit);
}

void inorderR(nlink h, void (*Visit)(Item x)) {
  if (h) {
    inorderR(h->l, Visit);
    if(h->item >= 0){
      printf("%d\n",h->item);
    }
    inorderR(h->r, Visit);
  }
}
void STinorder(void (*Visit)(Item x)){
  inorderR(head, Visit);
}

void postorderR(nlink h, void (*Visit)(Item x)) {
  if (h) {
    postorderR(h->l, Visit);
    postorderR(h->r, Visit);
    if(h->item >= 0){
      printf("%d\n",h->item);
    }
  }
}
void STpostorder(void (*Visit)(Item x)){
  postorderR(head, Visit);
}

int STmin(void (*Visit)(Item x)){
  nlink t = head;
  while((t->l)->l != NULL){
    t = t->l;
  }
  return t->item;
}

int STmax(void (*Visit)(Item x)){
  nlink t = head;
  while((t->r)->r != NULL){
    t = t->r;
  }
  return t->item;
}