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

class SinglyLinkedList {
    private:
        Node* head;

    public:
        SinglyLinkedList() {
            head = nullptr;
    }

        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
            }
    }

        void displayList() {
            if (head == nullptr) {
                cout << "List is empty.\n";
                return;
            }

            Node* temp = head;
            cout << "Linked List: ";
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
    }

        void findMiddle() {
            if (head == nullptr) {
                cout << "List is empty.\n";
                return;
            }

            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            cout << "The middle element is: " << slow->data << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << endl;
    list.displayList();

    list.findMiddle();

    return 0;
}
