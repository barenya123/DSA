#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        cout << value << " enqueued to the queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
        } else {
            int removedValue = front->data;
            Node* temp = front;

            if (front == rear) {
                front = rear = nullptr;
            } else {
                front = front->next;
                rear->next = front;
            }
            delete temp;
            cout << removedValue << " dequeued from the queue" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* current = front;

            cout << "Elements in the queue are: ";
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != front);

            cout << endl;
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
