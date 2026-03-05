//Problem: Convert an infix expression to postfix notation using stack.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    push('(');
    strcat(infix, ")");

    i = 0;
    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix[j++] = item;
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j++] = x;
                x = pop();
            }
        } else {
            while (precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);
    return 0;
}