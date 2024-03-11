#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int front, rear;
    int arr[SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
        } else {
            if (front == -1) {
                front = rear = 0;
                arr[rear] = value;
            } else {
                rear = (rear + 1) % SIZE;
                arr[rear] = value;
            }
            cout << value << " enqueued to the queue" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
        } else {
            int removedValue = arr[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            cout << removedValue << " dequeued from the queue" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Elements in the queue are: ";
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % SIZE;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.display();

    return 0;
}
