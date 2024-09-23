
#include <iostream>
using namespace std;

class Queue {
    int size;
    int front;
    int rear;
    int *Q;

public:
    // Constructor
    Queue(int size) {
        this->size = size;
        front = rear = 0;
        Q = new int[this->size];
    }

    // Destructor
    ~Queue() {
        delete[] Q;
    }

    // Enqueue operation
    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            cout << "Queue is Full" << endl;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }

    // Dequeue operation
    int dequeue() {
        int x = -1;
        if (front == rear) {
            cout << "Queue is Empty" << endl;
        } else {
            front = (front + 1) % size;
            x = Q[front];
        }
        return x;
    }

    // Display operation
    void display() {
        int i = front + 1;
        do {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue with size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will display "Queue is Full"
    q.display();

    cout << q.dequeue() << " "; // This will dequeue the first element (10)
    return 0;
}



