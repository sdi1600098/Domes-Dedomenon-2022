#define MAXVERTEX 20

typedef int Vertex;

typedef struct edge {
   Vertex endpoint;
   int weight;
   struct edge *nextedge;
   
} Edge;

typedef struct graph {
   int n;     /* number of vertices in the graph */
   int* visited;
   Edge *frontedge[MAXVERTEX];
} Graph;
