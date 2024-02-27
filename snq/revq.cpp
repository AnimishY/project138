// reverse a queue

#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int x) {
        if (count == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % capacity;
        count--;
        return x;
    }

    int peek() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    void reverse() {
        int n = count;
        int *temp = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = dequeue();
        }
        for (int i = 0; i < n; i++) {
            enqueue(temp[i]);
        }
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.reverse();
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}