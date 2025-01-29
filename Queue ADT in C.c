#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct {
    int patientId, severity;
} Patient;

typedef struct {
    Patient items[MAX];
    int front, rear, count;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

int isFull(Queue *q) {
    return q->count == MAX;
}

void enqueue(Queue *q, int patientId, int severity) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    int i = q->rear;
    while (i >= q->front && q->items[i % MAX].severity < severity) {
        q->items[(i + 1) % MAX] = q->items[i % MAX];
        i--;
    }
    q->items[(i + 1) % MAX] = (Patient){patientId, severity};
    q->rear = (q->rear + 1) % MAX;
    q->count++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int patientId = q->items[q->front].patientId;
    q->front = (q->front + 1) % MAX;
    q->count--;
    return patientId;
}

int queueSize(Queue *q) {
    return q->count;
}

int main() {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 201, 3);
    enqueue(&q, 202, 5);
    enqueue(&q, 203, 2);
    
    printf("dequeue - %d\n", dequeue(&q));
    printf("size of queue: %d\n", queueSize(&q));
    printf("is queue empty? - %s\n", isEmpty(&q) ? "Yes" : "No");

    return 0;
}
