// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both target nodes are smaller, move left
        if (p < root->data && q < root->data)
            root = root->left;
        // If both target nodes are larger, move right
        else if (p > root->data && q > root->data)
            root = root->right;
        // If they split (one left, one right) or we hit one of them, this is the LCA
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input N
    if (scanf("%d", &n) != 1) return 0;

    // Input N elements to build BST
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            root = insert(root, val);
        }
    }

    // Input two nodes to find LCA
    if (scanf("%d %d", &p, &q) == 2) {
        struct Node* lca = findLCA(root, p, q);
        if (lca) {
            printf("%d\n", lca->data);
        }
    }

    return 0;
}