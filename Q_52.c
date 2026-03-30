// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to build the tree from level-order traversal array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        
        // Insert left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
        }
        
        // Insert right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
    return root;
}

// The core LCA logic for a general Binary Tree
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL || root->data == p || root->data == q) {
        return root;
    }

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    // If p is found in one subtree and q in the other, this node is the LCA
    if (left != NULL && right != NULL) {
        return root;
    }

    // Otherwise, return the side that found a node
    return (left != NULL) ? left : right;
}

int main() {
    int n, p, q;
    
    // 1. Input N
    if (scanf("%d", &n) != 1) return 0;

    // 2. Input Level-order traversal
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Input p and q
    scanf("%d %d", &p, &q);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, p, q);

    if (lca) {
        printf("%d\n", lca->data);
    }

    free(arr);
    return 0;
}