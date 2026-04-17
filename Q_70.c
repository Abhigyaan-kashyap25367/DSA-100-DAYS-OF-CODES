//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].weight < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].weight;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].weight < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, src;
    if (scanf("%d %d %d", &n, &m, &src) != 3) return 0;
    struct Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    bellmanFord(n, m, edges, src);
    return 0;
}