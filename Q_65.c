//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int isCyclicUtil(struct Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int adjVertex = temp->data;

        if (!graph->visited[adjVertex]) {
            if (isCyclicUtil(graph, adjVertex, v))
                return 1;
        }
        else if (adjVertex != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int isCyclic(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (isCyclicUtil(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, edges, src, dest;
    scanf("%d", &n);
    struct Graph* graph = createGraph(n);
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    if (isCyclic(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    return 0;
}