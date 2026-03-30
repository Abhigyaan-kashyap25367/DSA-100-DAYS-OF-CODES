// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIdx) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(pre[(*preIdx)++]);

    if (inStart == inEnd) return root;

    int inIdx = search(in, inStart, inEnd, root->data);

    root->left = buildTree(in, pre, inStart, inIdx - 1, preIdx);
    root->right = buildTree(in, pre, inIdx + 1, inEnd, preIdx);

    return root;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* pre = (int*)malloc(sizeof(int) * n);
    int* in = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    int preIdx = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIdx);

    printPostorder(root);
    printf("\n");

    free(pre);
    free(in);
    return 0;
}