#include <stdio.h>
#include <stdlib.h>
#include "GraphT.h"

//static Graph* MyGraph;
// Create a node
Edge* createNode(int v) {
    Edge* newNode = malloc(sizeof(newNode));
    newNode->endpoint = v;
    newNode->nextedge = malloc(sizeof(newNode->nextedge));
    newNode->nextedge = NULL;
    return newNode;
}

// Create a graph
Graph* createAGraph(int vertices) {
    int i;
    Graph* graph = malloc(sizeof(Graph));
    graph->visited = malloc(vertices * sizeof(int));
    graph->n = vertices;
    for (i = 0; i < vertices; i++)
        graph->firstedge[i] = NULL;

    return graph;
}
static int NumofVertices;
Graph* Initialize(int v){
    NumofVertices = v;
    Graph* Graph = createAGraph(v);
    return Graph;
}

// Add edge
void addEdge(Graph* graph, int s, int d) {
    // Add edge from s to d
    Edge* newNode = malloc(sizeof(newNode));
    newNode = createNode(d);
    newNode->nextedge = graph->firstedge[s];
    graph->firstedge[s] = newNode;

}
void InsertEdge(Graph* G, int s, int d){
    addEdge(G, s, d);
}

// Print the graph
void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->n; v++) {
        Edge* temp = graph->firstedge[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
        printf(" -> %d ", temp->endpoint);
        temp = temp->nextedge;
        }
        printf("\n");
    }
}
void ShowGraph(Graph* G){
    printf("SHOWING GRAPH:\n");
    printGraph(G);
}


/*void DeFiSe(Graph* graph, Vertex v){
    Edge* adjList = graph->firstedge[v];
    Edge* temp = adjList;
    graph->visited[v] = 1;
    printf("Visited %d \n", v);
  while (temp != NULL) {
    int connectedVertex = temp->endpoint;
    if (graph->visited[connectedVertex] == 0) {
        DFS(graph, connectedVertex);
    }
    temp = temp->nextedge;
  }

}*/
Boolean visited[MAXVERTEX];

void Visit(int v){
    printf("VISITED %d\n", v);
}
static signed int pre[MAXVERTEX], post[MAXVERTEX], clock = 0;
void Traverse(Graph* G, Vertex v){
    Vertex w;
    Edge *curedge;
    pre[v]=clock;                             
    clock++;
    visited[v]=TRUE;
    Visit(v);
    curedge=G->firstedge[v]; /* curedge is a pointer to the first edge (v,_) of V */
    while (curedge){
        w=curedge->endpoint; /* w is a successor of v and (v,w) is the current edge */
        if (!visited[w]){
            printf("%d %d: Tree edge\n",v,w);
            Traverse(G, w);
        }
        else{
            if((pre[v] > pre[w]) && (post[v] < post[w]))      //v was visited after w
                printf("%d %d: Back edge\n",v,w);
            else if ((pre[v] < pre[w]) && (post[v] > post[w]))    //v was visited before w
                printf("%d %d: Forward edge\n",v,w);
            else if ((pre[v] > pre[w]) && (post[v] > post[w]))    //
                printf("%d %d: Cross edge\n",v,w);
        }
        post[v]=clock;
        clock++;
        curedge=curedge->nextedge; /*curedge is a pointer to the next edge (v,_) of V */
    }
    
}

void DepthFirst(Graph* G){
    Vertex v;
    for (v=0; v < G->n; v++)
        visited[v]=FALSE;
    for (v=0; v < G->n; v++)
        if (!visited[v]) Traverse(G, v);
    clock = 0;
}

void DFS(Graph* G){
    printf("DEPTH FIRST:\n");
    DepthFirst(G);
    printf("\n");
}

void InitializeQueue(Queue *Q){
    Q->Count=0;
    Q->Front=0;
    Q->Rear=0;
}
int Empty(Queue *Q){
    return(Q->Count==0);
}
int Full(Queue *Q){
    return(Q->Count==MAXQUEUESIZE);
}
void Insert(ItemType R, Queue *Q){
    if (Q->Count==MAXQUEUESIZE){
        printf("attempt to insert item into a full queue");
    } 
    else {
        Q->Items[Q->Rear]=R;
        Q->Rear=(Q->Rear+1)%MAXQUEUESIZE;
        ++(Q->Count);
    }
}
void Remove(Queue *Q, ItemType *F){
    if (Q->Count==0){
        printf("attempt to remove item from empty queue");
    } 
    else {
        *F=Q->Items[Q->Front];
        Q->Front=(Q->Front+1)%MAXQUEUESIZE;
        --(Q->Count);
    }
}

void BreadthFirst(Graph* G){
    Queue Q;
    Boolean visited[MAXVERTEX];
    Vertex v, u, w;
    Edge *curedge;
    for (v=0; v < G->n; v++)
        visited[v]=FALSE;
    InitializeQueue(&Q);
    for (u=0; u < G->n; u++)
        if (!visited[u]){
            Insert(u, &Q);
            do {
                Remove(&Q, &v);;
                if (!visited[v]){
                    visited[v]=TRUE;
                    Visit(v);
                }

                curedge=G->firstedge[v]; /* curedge is a pointer to the first edge (v,_) of V */
                while (curedge){
                    w=curedge->endpoint; /* w is a successor of v and (v,w) is the current edge */
                    if (!visited[w]) Insert(w, &Q);
                    curedge=curedge->nextedge; /*curedge is a pointer to the next edge (v,_) of V */
                }
            } while (!Empty(&Q));
        }
}

void BFS(Graph* G){
    printf("BREADTH FIRST:\n");
    BreadthFirst(G);
    printf("\n");
}
void TraverseWithoutPrint(Graph* G, Graph* G2, int v){
    Vertex w;
    Edge *curedge;
    pre[v]=clock;                             
    clock++;
    visited[v]=TRUE;
    curedge = G->firstedge[v];                  /* curedge is a pointer to the first edge (v,_) of V */
    while (curedge){
        w=curedge->endpoint;                    /* w is a successor of v and (v,w) is the current edge */
        if (!visited[w]) TraverseWithoutPrint(G, G2, w);
        InsertEdge(G2, w, v);
        post[v]=clock;
        clock++;
        curedge=curedge->nextedge;              /*curedge is a pointer to the next edge (v,_) of V */
    }
}

Graph* ReverseGraph(Graph* G){
    Graph* G2 = Initialize(NumofVertices);
    Vertex v;
    for (v=0; v < G->n; v++)
        visited[v]=FALSE;
    for (v=0; v < G->n; v++)
        if (!visited[v]) TraverseWithoutPrint(G, G2, v);
    return G2;
}

void TraverseStrongComponents(Graph* G, int v){
    Vertex w;
    Edge *curedge;
    visited[v]=TRUE;
    printf("%d ", v);
    curedge = G->firstedge[v];                  /* curedge is a pointer to the first edge (v,_) of V */
    while (curedge){
        w=curedge->endpoint;                    /* w is a successor of v and (v,w) is the current edge */
        if (!visited[w]) TraverseStrongComponents(G, w);
        curedge=curedge->nextedge;              /* curedge is a pointer to the next edge (v,_) of V */
    }
}

void StrongComponents(Graph* G){
    printf("\n");
    clock = 0;
    Graph* G2 = ReverseGraph(G);
    int temp_max = 0;
    int flag = 0;
    int i;
    for (i=0; i < G2->n; i++)
        visited[i]=FALSE;
    while(flag != 1){
        for(i = 0 ; i < NumofVertices ; i++){
            if(post[i] >= post[temp_max]){
                temp_max = i;
            }
        }
        if(!visited[temp_max]){
            printf("Strong Components: ");
            TraverseStrongComponents(G2, temp_max);
            printf("\n");
        }
        post[temp_max] = -1;
        for(i = 0 ; i < NumofVertices ; i++){
            if(post[i] != -1){
                flag = 0;
            }
            else{
                flag = 1;
            }
        }
    }
}