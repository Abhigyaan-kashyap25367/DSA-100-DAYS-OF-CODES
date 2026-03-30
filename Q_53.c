// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for Level Order Tree Construction and Traversal
struct QueueNode {
    struct Node* treeNode;
    int hd; // Horizontal Distance
    struct QueueNode* next;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** q = (struct Node**)malloc(sizeof(struct Node*) * n);
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        if (i < n) {
            curr->left = createNode(arr[i++]);
            if (curr->left) q[r++] = curr->left;
        }
        if (i < n) {
            curr->right = createNode(arr[i++]);
            if (curr->right) q[r++] = curr->right;
        }
    }
    free(q);
    return root;
}

// Find the leftmost and rightmost HD
void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Print nodes for a specific vertical line using BFS to maintain top-to-bottom order
void printVerticalLine(struct Node* root, int line_no) {
    if (root == NULL) return;

    // BFS Queue to store node and its HD
    struct Node* nodeQ[100];
    int hdQ[100];
    int f = 0, r = 0;

    nodeQ[r] = root;
    hdQ[r++] = 0;

    int first = 1;
    while (f < r) {
        struct Node* curr = nodeQ[f];
        int curr_hd = hdQ[f++];

        if (curr_hd == line_no) {
            if (!first) printf(" ");
            printf("%d", curr->data);
            first = 0;
        }

        if (curr->left) {
            nodeQ[r] = curr->left;
            hdQ[r++] = curr_hd - 1;
        }
        if (curr->right) {
            nodeQ[r] = curr->right;
            hdQ[r++] = curr_hd + 1;
        }
    }
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    for (int line = min; line <= max; line++) {
        printVerticalLine(root, line);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter level-order traversal (use -1 for NULL): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    printf("\nVertical Order Traversal:\n");
    verticalOrder(root);

    free(arr);
    return 0;
}