#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "BT.h"

int main(){
    int skatoula = 10;
    link root;
    root = MakeTree(skatoula);
    int Current_Tree = 0;
    int ID = 0;
    InsertLeft(Current_Tree, ID, 20);
    InsertRight(Current_Tree, root, 30);
    Item parent = Parent(Current_Tree, ID);
    printf("parent is:%d\n", parent);
    printf("height of tree is %d\n", Height(Current_Tree));
    printf("size of tree is %d\n", Size(Current_Tree));
    printLevelOrder(Current_Tree);
    /*Item element_of_root = Root(Current_Tree);
    
    Item parent = Parent(Current_Tree, root);
    printf("parent is:%d\n", parent);
    //printf("sibling is %d\n", Sibling(root->r));
    if(IsExternal(root->r) == 1){
        printf("node is external\n");
    }
    else{
        printf("node is not external\n");
    }

    if(IsInternal(root->r) == 1){
        printf("node is internal\n");
    }
    else{
        printf("node is not internal\n");
    }
    printf("size of tree is %d\n", Size(root));*/
    //Visualize();
}