//Problem: Deque (Double-Ended Queue) A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

typedef struct {
    Node *front, *rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;
    if (dq->front == NULL) dq->rear = newNode;
    else dq->front->prev = newNode;
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (dq->rear == NULL) dq->front = newNode;
    else dq->rear->next = newNode;
    dq->rear = newNode;
    dq->size++;
}

void pop_front(Deque* dq) {
    if (dq->size == 0) return;
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (dq->size == 0) return;
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
    dq->size--;
}

void display(Deque* dq) {
    Node* curr = dq->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();
    int choice, val;

    while (1) {
        printf("1.push_f 2.push_b 3.pop_f 4.pop_b 5.size 6.exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                scanf("%d", &val);
                push_front(dq, val);
                display(dq);
                break;
            case 2:
                scanf("%d", &val);
                push_back(dq, val);
                display(dq);
                break;
            case 3:
                pop_front(dq);
                display(dq);
                break;
            case 4:
                pop_back(dq);
                display(dq);
                break;
            case 5:
                printf("Size: %d\n", dq->size);
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}