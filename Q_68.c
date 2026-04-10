//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

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

void kahnTopologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* inDegree = (int*)calloc(V, sizeof(int));
    int* topoOrder = (int*)malloc(V * sizeof(int));
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0, count = 0;

    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            inDegree[temp->dest]++;
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        struct Node* temp = graph->adj[u];
        while (temp) {
            if (--inDegree[temp->dest] == 0) {
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }

    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Ordering (Kahn's): ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topoOrder[i]);
        }
        printf("\n");
    }

    free(inDegree);
    free(topoOrder);
    free(queue);
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

    kahnTopologicalSort(graph);

    return 0;
}