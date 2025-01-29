#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* temp = * top;
 
void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    return data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

void decimalToBinary(int n) {
    Node* stack = NULL;
    while (n > 0) {
        push(&stack, n % 2);
        n = n / 2;
    }
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    printf("Binary equivalent: ");
    decimalToBinary(decimalNumber);
    
    return 0;
}
