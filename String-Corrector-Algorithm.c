#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, char data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

char dequeue(Queue* q) {
    if (isEmpty(q))
        return '\0';
    Node* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void stringCorrector() {
    Queue q;
    initQueue(&q);
    char ch;

    printf("Enter characters:\n");

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            if (islower(ch))
                ch = toupper(ch);
            enqueue(&q, ch);
        } else if (isdigit(ch) || ispunct(ch)) {
            continue;
        } else if (isspace(ch)) {
            enqueue(&q, ' ');
        } else
            continue;
    }

    printf("Processed output:\n");
    while (!isEmpty(&q))
        putchar(dequeue(&q));
    printf("\n");
}

int main() {
    stringCorrector();
    return 0;
}


