//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

bool isCyclicUtil(int v, bool visited[], bool recStack[], struct Graph* graph) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        struct Node* temp = graph->adjLists[v];
        while (temp != NULL) {
            int neighbor = temp->dest;
            if (recStack[neighbor]) return true;
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, graph))
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false;
    return false;
}

int main() {
    int V, E, src, dest;

    printf("Enter number of vertices: ");
    if (scanf("%d", &V) != 1) return 1;

    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    if (scanf("%d", &E) != 1) return 1;

    for (int i = 0; i < E; i++) {
        printf("Edge %d (src dest): ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src >= V || dest >= V || src < 0 || dest < 0) {
            printf("Invalid input. Try again.\n");
            i--;
        } else {
            addEdge(graph, src, dest);
        }
    }

    bool* visited = calloc(V, sizeof(bool));
    bool* recStack = calloc(V, sizeof(bool));
    bool cycleFound = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack, graph)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) printf("YES\n");
    else printf("NO\n");

    free(visited);
    free(recStack);

    return 0;
}