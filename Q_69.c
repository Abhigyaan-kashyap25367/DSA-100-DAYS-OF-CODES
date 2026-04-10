//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i) graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        minHeap->pos[minHeap->array[smallest]->v] = idx;
        minHeap->pos[minHeap->array[idx]->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V];
    struct MinHeap* minHeap = malloc(sizeof(struct MinHeap));
    minHeap->pos = malloc(V * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = V;
    minHeap->array = malloc(V * sizeof(struct MinHeapNode*));

    for (int v = 0; v < V; ++v) {
        dist[v] = INT_MAX;
        minHeap->array[v] = malloc(sizeof(struct MinHeapNode));
        minHeap->array[v]->v = v;
        minHeap->array[v]->dist = dist[v];
        minHeap->pos[v] = v;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    while (minHeap->size != 0) {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (minHeap->pos[v] < minHeap->size && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("\nVertex   Distance from Source (%d)\n", src);
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) printf("%d \t\t INF\n", i);
        else printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V, E, src, u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        if (u >= V || v >= V || u < 0 || v < 0) {
            printf("Invalid vertices. Use 0 to %d.\n", V - 1);
            i--;
        } else {
            addEdge(graph, u, v, w);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    if (src >= 0 && src < V) {
        dijkstra(graph, src);
    } else {
        printf("Invalid source vertex.\n");
    }

    return 0;
}