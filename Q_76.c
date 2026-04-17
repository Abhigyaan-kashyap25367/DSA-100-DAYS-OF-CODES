// Problem Statement
// Using DFS or BFS, count number of connected components.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adj;
    int* visited;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

void dfs(struct Graph* graph, int v) {
    graph->visited[v] = 1;
    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!graph->visited[temp->dest]) {
            dfs(graph, temp->dest);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->n = n;
    graph->adj = malloc((n + 1) * sizeof(struct Node*));
    graph->visited = calloc((n + 1), sizeof(int));

    for (int i = 0; i <= n; i++) graph->adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // Undirected graph edges
        struct Node* newNode = createNode(v);
        newNode->next = graph->adj[u];
        graph->adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = graph->adj[v];
        graph->adj[v] = newNode;
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!graph->visited[i]) {
            components++;
            dfs(graph, i);
        }
    }

    printf("%d\n", components);

    return 0;
}