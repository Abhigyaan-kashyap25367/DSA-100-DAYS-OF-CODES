//Problem: Count Leaf Nodes Implement the solution for this problem.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* constructTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n;
    scanf("%d", &n) ;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = constructTree(arr, n);
    printf("%d\n", countLeafNodes(root));

    return 0;
}