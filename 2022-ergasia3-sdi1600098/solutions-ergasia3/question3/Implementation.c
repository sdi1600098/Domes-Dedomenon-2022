#include <stdio.h>
#include <stdlib.h>
#include "GraphT.h"

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
        graph->frontedge[i] = NULL;

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
    newNode->nextedge = graph->frontedge[s];
    graph->frontedge[s] = newNode;
    newNode = malloc(sizeof(newNode));
    newNode = createNode(s);
    newNode->nextedge = graph->frontedge[d];
    graph->frontedge[d] = newNode;
}
void InsertEdge(Graph* G, int s, int d){
    addEdge(G, s, d);
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->n; v++) {
        Edge* temp = graph->frontedge[v];
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

int visited[MAXVERTEX];
void Traverse(Graph* G, int v){
    Vertex w;
    Edge *curedge;
    visited[v] = 1;
    curedge = G->frontedge[v];                  /* curedge is a pointer to the first edge (v,_) of V */
    while (curedge){
        w=curedge->endpoint;                    /* w is a successor of v and (v,w) is the current edge */
        if (!visited[w]) Traverse(G, w);
        curedge=curedge->nextedge;              /*curedge is a pointer to the next edge (v,_) of V */
    }
}

void SimplePathCheck(Graph* G, int first, int second){
    Vertex v;
    for (v=0; v < G->n; v++)
        visited[v] = 0;
    Traverse(G, first);
    if(visited[second] == 1)
        printf("PATH EXISTS\n\n");
    else 
        printf("PATH DOES NOT EXIST\n\n");
}