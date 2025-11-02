#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;

public:
    CircularList(){ 
        head = NULL;
    }

    void insertLast(int x){
        Node* n = new Node(x);
        if (head == NULL) {
            head = n;
            head->next = head;
            return;
        }

        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void displayWithRepeatHead(){
        if (head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data;
        cout << endl;
    }
};

int main(){
    CircularList cl;
    cl.insertLast(20);
    cl.insertLast(100);
    cl.insertLast(40);
    cl.insertLast(80);
    cl.insertLast(60);

    cout << "Output: ";
    cl.displayWithRepeatHead();
    return 0;
}
