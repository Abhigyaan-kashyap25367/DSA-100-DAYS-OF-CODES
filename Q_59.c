// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.
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

struct Node* buildTree(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) return node;

    int iIndex = search(in, inStart, inEnd, node->data);

    node->right = buildTree(in, post, iIndex + 1, inEnd, postIndex);
    node->left = buildTree(in, post, inStart, iIndex - 1, postIndex);

    return node;
}

void printPreOrder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printPreOrder(root);
    printf("\n");

    return 0;
}