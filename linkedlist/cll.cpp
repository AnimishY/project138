// circular linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        Node* temp = head->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head->next);
        cout << endl;
    }
    void deleteNode(int data) {
        if (head == NULL) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == data) {
                if (temp == head) {
                    head = head->next;
                }
                prev->next = temp->next;
                delete temp;
                cout << "Node with value " << data << " deleted." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node with value " << data << " not found in the list." << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int n;
    cout << "Enter the number of values: ";
    cin >> n;

    int hold;
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> hold;
        cll.insert(hold);
    }
    cll.display();
    int del;
    cout << "Enter the value to delete: ";
    cin >> del;
    cll.deleteNode(del);
    cll.display();
    return 0;
}
