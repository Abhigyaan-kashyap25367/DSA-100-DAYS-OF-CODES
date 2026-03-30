//  Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
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

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** q = (struct Node**)malloc(sizeof(struct Node*) * n);
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (f < r && i < n) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    free(q);
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;

    struct Node** s1 = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node** s2 = (struct Node**)malloc(sizeof(struct Node*) * n);
    int top1 = -1, top2 = -1;

    s1[++top1] = root;
    int leftToRight = 1;

    while (top1 >= 0) {
        while (top1 >= 0) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);

            if (leftToRight) {
                if (temp->left) s2[++top2] = temp->left;
                if (temp->right) s2[++top2] = temp->right;
            } else {
                if (temp->right) s2[++top2] = temp->right;
                if (temp->left) s2[++top2] = temp->left;
            }
        }

        struct Node** tempStack = s1;
        s1 = s2;
        s2 = tempStack;
        top1 = top2;
        top2 = -1;
        leftToRight = !leftToRight;
    }
    free(s1);
    free(s2);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root, n);

    free(arr);
    return 0;
}