// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int graph[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (graph[u][v] == 0 || w < graph[u][v]) {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int key[n + 1];
    int mstSet[n + 1];
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 1; v <= n; v++) {
            if (mstSet[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break;

        mstSet[u] = 1;
        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);

    return 0;
}