/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */
void STinit(int);
 int STcount();
void STinsert(Item);
Item STsearch(Key);
void STdelete(Item);
Item STselect(int);
void STsort(void (*visit)(Item));
///////////
void STpreorder(void (*Visit)(Item x));
void STinorder(void (*Visit)(Item x));
void STpostorder(void (*Visit)(Item x));

int STmin(void (*Visit)(Item x));
int STmax(void (*Visit)(Item x));
void STinsert1(Item key, int N);
void STinsertT(Item key);