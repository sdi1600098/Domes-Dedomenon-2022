#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

static link root_list[10], head_list[10];
static int tree_count = 0;
link NewNode(Item item, link l, link r, int count){
    // Allocate memory for new node
    link node = malloc(sizeof(node));
    // Assign data to this node
    node->item = item;
    node->ID = count + 1;
    // Initialize left and
    // right children as NULL
    node->l = l;
    node->r = r;
    return node;
}
link MakeTree(Item item){
    
    head_list[tree_count] = (root_list[tree_count] = NewNode(item, NULL, NULL, -1));
    return root_list[tree_count];
}

Item Root(int Current_Tree){
    return root_list[Current_Tree]->item;
}
link FindParent(Item key, link node, Item parent){
    if(node == NULL || node->ID == key){
        return NULL;
    }
    if((node->l != NULL && node->l->ID == key) || (node->r != NULL && node->r->ID == key)){
        return node;
    }
    link temp = FindParent(key, node->l, node->ID);
    if(temp != NULL){
        return temp;
    }
    temp = FindParent(key, node->r, node->ID);
    return temp;
}
Item Parent(int Current_Tree, int key){
    
    link temp = FindParent(key, root_list[Current_Tree], -1);
    if(temp == NULL){
        return -1;
    }
    return temp->item;
}

Item Sibling(int Current_Tree, Item ID){
    Item child = ID;
    link parent = FindParent(ID, root_list[Current_Tree], -1);;
    if (parent->l->ID == child){
        return parent->r->item;
    }
    else{
        return parent->l->item;
    }
}

void InsertLeft(int Current_Tree, int ID, Item item){
    link node = FindParent(ID, root_list[Current_Tree], -1);
    if(node == NULL){
        root_list[Current_Tree]->l = NewNode(item, NULL, NULL, 0);
    }
    else if(node->l->ID == ID){
        node = node->l;
        node->l = NewNode(item, NULL, NULL, node->ID);
    }
    else{
        node = node->r;
        node->l = NewNode(item, NULL, NULL, node->ID);
    }
}

void InsertRight(int Current_Tree, int ID, Item item){
    link node = FindParent(ID, root_list[Current_Tree], -1);
    if(node == NULL){
        root_list[Current_Tree]->r = NewNode(item, NULL, NULL, 0);
    }
    else if(node->l->ID == ID){
        node = node->l;
        node->r = NewNode(item, NULL, NULL, node->ID);
    }
    else{
        node = node->r;
        node->r = NewNode(item, NULL, NULL, node->ID);
    }
}
/*
int IsExternal(int Current_Tree, int ID){
    if(node->l == NULL && node->r == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int IsInternal(int Current_Tree, int ID){
    if(node->l != NULL || node->r != NULL){
            return 1;
        }
    else{
        return 0;
    }
}
*/
int CalculateHeight(link root){
    if(root == NULL){
        return 0;
    }
    int LeftHeight = CalculateHeight(root->l);
    int RightHeight = CalculateHeight(root->r);
    if(LeftHeight > RightHeight){
        return LeftHeight + 1;
    }
    else{
        return RightHeight + 1;
    }
}
int Height(int Current_Tree){
    int temp = CalculateHeight(root_list[Current_Tree]);
}

int CalculateSize(link root){
    if (root == NULL)
        return 0;
    else    
        return(CalculateSize(root->l) + 1 + CalculateSize(root->r));
}
int Size(int Current_Tree){
    int  temp = CalculateSize(root_list[Current_Tree]);
}
/*
link Search(link root, int key)
*/
void printCurrentLevel(link root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->item);
    else if (level > 1) {
        printCurrentLevel(root->l, level - 1);
        printCurrentLevel(root->r, level - 1);
    }
}

void printLevelOrder(int Current_Tree)
{
    int h = Height(Current_Tree);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root_list[Current_Tree], i);
}

/*void Visualize(void){
    for(int i = 0 ; i < 9 ; i++){
        if(root_list[i] != NULL){
            printf("%d(%d)\n/   \\\n\n",root_list[i]->item, root_list[i]->ID);
        }
    }
}*/