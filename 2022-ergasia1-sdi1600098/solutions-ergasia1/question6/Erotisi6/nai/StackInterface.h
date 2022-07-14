#include "StackTypes.h"
void InitializeStackOp(OpStack *);
int EmptyOp(OpStack *);
int FullOp(OpStack *);
void PushOp(ItemTypeOp, OpStack *);
void PopOp(OpStack *, ItemTypeOp *);

/////

void InitializeStackNum(NumStack *);
int EmptyNum(NumStack *);
int FullNum(NumStack *);
void PushNum(ItemTypeNum, NumStack *);
void PopNum(NumStack *, ItemTypeNum *);

////

int Evaluation(NumStack *Numbers, OpStack *Operators, char PostfixString[100]);
void Process(NumStack *Numbers, OpStack *Operators);