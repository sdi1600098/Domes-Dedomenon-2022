typedef int Item;
typedef int Key;
#define NULLitem -1 /* NULLitem is a constant */
/*#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))*/
typedef struct STnode* link;
struct STnode { 
    Item item;
    Item ID;
    link l; 
    link r;
};