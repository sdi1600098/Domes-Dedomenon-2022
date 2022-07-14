#define MAXVERTEX 20

typedef enum {FALSE, TRUE} Boolean;

typedef int Vertex;

typedef struct edge {
   Vertex endpoint;
   struct edge *nextedge;
} Edge;

typedef struct graph {
   int n;     /* number of vertices in the graph */
   int* visited;
   Edge *firstedge[MAXVERTEX];
} Graph;

#define MAXQUEUESIZE 100

typedef int ItemType;
/* the item type can be arbitrary */
typedef struct {
   int Count;
   int Front;
   int Rear;
   ItemType Items[MAXQUEUESIZE];
} Queue;