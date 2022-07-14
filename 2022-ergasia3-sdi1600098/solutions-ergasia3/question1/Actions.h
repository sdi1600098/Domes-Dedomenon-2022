void InitializeQueue(Queue *Q);
int Empty(Queue *Q);
int Full(Queue *Q);
void Insert(ItemType R, Queue *Q);
void Remove(Queue *Q, ItemType *F);

Graph* Initialize(int v);
void InsertEdge(Graph* G, int s, int d);
void ShowGraph(Graph* G);
void DFS(Graph* G);
void BFS(Graph* G);
Graph* ReverseGraph(Graph* G);
void StrongComponents(Graph* G);