#include <stdio.h>
#include <stdlib.h>

// Define the Queue structure
struct Queue {
    int size;  // Maximum size of the queue
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int *Q;    // Pointer to the array holding the queue elements
};

// Function to create a queue
void create(struct Queue *q, int size) {
    q->size = size; // Set the size of the queue
    q->front = q->rear = -1; // Initialize front and rear to -1
    q->Q = (int *)malloc(q->size * sizeof(int)); // Allocate memory for the queue array
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        // If the queue is full, print an error message
        printf("Queue is Full\n");
    } else {
        // Otherwise, increment rear and add the element to the queue
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        // If the queue is empty, print an error message
        printf("Queue is Empty\n");
    } else {
        // Otherwise, increment front and remove the element from the queue
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Function to display the elements of the queue
void Display(struct Queue q) {
    for (int i = q.front + 1; i <= q.rear; i++) {
        // Print each element from front to rear
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue q; // Declare a queue
    create(&q, 5); // Create the queue with a size of 5

    // Enqueue elements into the queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    // Display the elements of the queue
    Display(q);

    // Dequeue an element and print it
    printf("%d ", dequeue(&q));

    return 0;
}
