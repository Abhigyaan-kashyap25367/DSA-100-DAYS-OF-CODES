//Problem Statement
//Implement a hash table using quadratic probing with formula:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int m, q;
    if (scanf("%d %d", &m, &q) != 2) return;

    int *hashTable = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) hashTable[i] = -1;

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;
                if (hashTable[index] == -1) {
                    hashTable[index] = key;
                    break;
                }
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;
                if (hashTable[index] == key) {
                    found = 1;
                    break;
                } else if (hashTable[index] == -1) {
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    free(hashTable);
}

int main() {
    solve();
    return 0;
}