typedef struct{
    int OpCount;
    char OpItems[100];
} OpStack;

typedef char ItemTypeOp; 

typedef struct{
    int NumCount;
    int NumItems[100];
} NumStack;

typedef char ItemTypeNum;