
link MakeTree(Item item);   //done
Item Root(int Current_Tree);       //done
Item Parent(int Current_Tree, int ID);     //done
Item Sibling(int Current_Tree, int ID);    //done
int IsInternal(int Current_Tree, int ID);  //
int IsExternal(int Current_Tree, int ID);  //
void InsertLeft(int Current_Tree, int ID, Item item);  //done
void InsertRight(int Current_Tree, link node, Item item); //done
void Attach(link node, link left, link right);
void Remove(link node);
void Destroy(link tree);
int Height(int Current_Tree);  //done
int Size(int Current_Tree);    //done
link Search(link root, Key key);

void printLevelOrder(int Current_Tree);
void Visualize(void);