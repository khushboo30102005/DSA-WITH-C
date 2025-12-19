#include <stdio.h>
#define MAX 5


struct Queue {
int arr[MAX];
int front, rear;
};


void initQueue(struct Queue *q) {
q->front = -1;
q->rear = -1;
}


int isEmpty(struct Queue *q) {
return (q->front == -1);
}


int isFull(struct Queue *q) {
return (q->rear == MAX - 1);
}


void enqueue(struct Queue *q, int data) {
if (isFull(q)) {
printf("Queue Overflow! Cannot insert.");
return;
}
if (isEmpty(q)) {
q->front = 0;
}
q->rear++;
q->arr[q->rear] = data;
printf("\nEnqueued: %d", data);
}


void dequeue(struct Queue *q) {
if (isEmpty(q)) {
printf("Queue Underflow! Cannot delete.");
return;
}
printf("\nDequeued: %d", q->arr[q->front]);
if (q->front == q->rear) {
q->front = q->rear = -1;
} else {
q->front++;
}
}


void display(struct Queue *q) {
if (isEmpty(q)) {
printf("Queue is empty.");
return;
}
printf("\nQueue elements: " );
for (int i = q->front; i <= q->rear; i++) {
printf("%d ", q->arr[i]);
}
printf("");
}


int main() {
struct Queue q;
initQueue(&q);


enqueue(&q, 10);
enqueue(&q, 20);
enqueue(&q, 30);
display(&q);


dequeue(&q);
display(&q);


return 0;
};