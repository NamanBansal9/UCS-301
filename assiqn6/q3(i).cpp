#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    Node* head;

public:
    DoublyLinkedList(){ 
        head = NULL;
    }

    void insertLast(int x){
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    int size(){
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList dl;
    dl.insertLast(10);
    dl.insertLast(20);
    dl.insertLast(30);
    dl.insertLast(40);
    cout << "Size of Doubly Linked List = " << dl.size();
    return 0;
}
