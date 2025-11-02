#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void insertLast(int x){
        Node* n = new Node(x);
        if(!head){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    bool isCircular(){
        if (head == NULL) return false;

        Node* temp = head->next;

        while(temp != NULL && temp != head){
            temp = temp->next;
        }

        return (temp == head);
    }
};

int main() {
    LinkedList l;
    l.insertLast(10);
    l.insertLast(20);
    l.insertLast(30);
    l.head->next->next->next = l.head;
    if (l.isCircular())
        cout << "It is a Circular Linked List";
    else
        cout << "It is NOT a Circular Linked List";

    return 0;
}
