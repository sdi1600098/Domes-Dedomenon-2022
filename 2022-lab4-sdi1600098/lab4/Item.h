typedef int Key;
typedef struct node* Item;
struct node{
    char onoma[20];
    char epitheto[20];
};
#define NULLitem -1 /* NULLitem is a constant */
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

Item ITEMscan(int *);
//void ITEMshow(Item);