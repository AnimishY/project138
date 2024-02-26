// doubly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
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

        while (temp != NULL && temp->data != data) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Element not found in the list." << endl;
            return;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    cout << "Enter the number of values: ";
    cin >> n;

    int hold;
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> hold;
        dll.insert(hold);
    }
    dll.display();
    int del;
    cout << "Enter the value to delete: ";
    cin >> del;
    dll.deleteNode(del);
    dll.display();
    return 0;
}
