// singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() {
        head = NULL;
    }
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == data) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found in the list." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
};

int main() {
    SinglyLinkedList sll;
    int n;
    cout << "Enter the number of values: ";
    cin >> n;

    int hold;
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> hold;
        sll.insert(hold);
    }
    sll.display();
    int del;
    cout << "Enter the value to delete: ";
    cin >> del;
    sll.deleteNode(del);
    sll.display();
    return 0;
}
