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
void addEdge(Graph* graph, int s, int d, int weight) {
    // Add edge from s to d
    Edge* newNode = malloc(sizeof(newNode));
    newNode = createNode(d);
    newNode->weight = weight;
    newNode->nextedge = graph->frontedge[s];
    graph->frontedge[s] = newNode;
    newNode = malloc(sizeof(newNode));
    newNode = createNode(s);
    newNode->weight = weight;
    newNode->nextedge = graph->frontedge[d];
    graph->frontedge[d] = newNode;
}
void InsertEdge(Graph* G, int s, int d, int weight){
    addEdge(G, s, d, weight);
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->n; v++) {
        Edge* temp = graph->frontedge[v];
        printf("\n Vertex %d\n: ", v);
        while (temp) {
        printf(" -> %d(%d) ", temp->endpoint, temp->weight);
        temp = temp->nextedge;
        }
        printf("\n");
    }
}
void ShowGraph(Graph* G){
    printf("SHOWING GRAPH:\n");
    printGraph(G);
}

int minKey(int key[], int mstSet[], Graph* G){
    // Initialize min value
    int min = 1000, min_index;
 
    for (int v = 0; v < G->n; v++){
        if (mstSet[v] == 0 && key[v] < min){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], Graph* G){
    printf("Edge \tWeight\n");
    for (int i = 1; i < MAXVERTEX; i++)
        printf("%d - %d \t%d \n", parent[i], i, G->frontedge[i]->weight);
}

void PrimJarnik(Graph* G){
    // Array to store constructed MST
    signed int parent[G->n];
    // Key values used to pick minimum weight edge in cut
    signed int key[G->n];
    // To represent set of vertices included in MST
    int mstSet[G->n];
    for (int i = 0; i < G->n; i++){
        key[i] = -1;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < G->n - 1; i++) {
            // Pick the minimum key vertex from the
            // set of vertices not yet included in MST
            int u = minKey(key, mstSet, G);
    
            // Add the picked vertex to the MST Set
            mstSet[u] = 1;
    
            // Update key value and parent index of
            // the adjacent vertices of the picked vertex.
            // Consider only those vertices which are not
            // yet included in MST
            for (int v = 0; v < G->n; v++){
                // mstSet[v] is false for vertices not yet included in MST
                if (G->frontedge[u] && mstSet[v] == 0 && G->frontedge[u]->weight < key[v]){
                    parent[v] = u;
                    key[v] = G->frontedge[u]->weight;
                }
        }
    
        // print the constructed MST
        printMST(parent, G);
    }
}

void MinimumSpanningTree(Graph* G){
    PrimJarnik(G);
}