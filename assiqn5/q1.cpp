#include <iostream>
using namespace std;

class Node{
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

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
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
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertBeforeAfter(int target, int value, bool insertAfter) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (!insertAfter && head->data == target) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (insertAfter && temp->data == target) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " after " << target << ".\n";
                return;
            } else if (!insertAfter && temp->next != nullptr && temp->next->data == target) {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " before " << target << ".\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Target node not found.\n";
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted node with value " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted node with value " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << "Deleted node with value " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete specific node by value
    void deleteSpecific(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << value << ".\n";
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node not found.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted node with value " << value << ".\n";
        delete nodeToDelete;
    }

    void searchNode(int value) {
        int pos = 1;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found.\n";
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
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n=== Singly Linked List Menu ===\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> value;
            list.insertBeforeAfter(target, value, false);
            break;
        case 4:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> value;
            list.insertBeforeAfter(target, value, true);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecific(value);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            list.searchNode(value);
            break;
        case 9:
            list.displayList();
            break;
        case 10:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
