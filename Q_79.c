// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int graph[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (graph[u][v] == -1 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int source;
    scanf("%d", &source);

    int dist[n + 1];
    int visited[n + 1];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != -1 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            printf("-1 ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");

    return 0;
}