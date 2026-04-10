//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void topoSortUtil(int v, bool visited[], int stack[], int* top, struct Graph* graph) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            topoSortUtil(temp->dest, visited, stack, top, graph);
        }
        temp = temp->next;
    }

    // Push to stack after visiting all neighbors
    stack[(*top)++] = v;
}

void topologicalSort(struct Graph* graph) {
    bool* visited = calloc(graph->V, sizeof(bool));
    int* stack = malloc(graph->V * sizeof(int));
    int top = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topoSortUtil(i, visited, stack, &top, graph);
        }
    }

    printf("Topological Ordering: ");
    while (top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");

    free(visited);
    free(stack);
}

int main() {
    int V, E, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}