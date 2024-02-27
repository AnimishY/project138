// write code to reverse a stack

#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void reverse() {
        int n = top + 1;
        int *temp = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            arr[i] = temp[n-i-1];
        }
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.reverse();
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}