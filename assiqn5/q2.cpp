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

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        cout << "All occurrences of " << key << " deleted successfully.\n";
    }
};

int main() {
    SinglyLinkedList list;
    int n, value, key;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout <<endl<<"Original list : ";
    list.displayList();

    cout <<endl<< "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "The key " << key << " occurs " << count << " time(s) in the list.\n";

    list.deleteAllOccurrences(key);

    cout <<endl<< "Updated list : ";
    list.displayList();

    return 0;
}
