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

class CircularList{
    Node* head;

public:
    CircularList(){
        head = NULL;
    }

    void insertLast(int x){
        Node* n = new Node(x);
        if (!head) {
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

    int size(){
        if (!head) return 0;

        int count = 0;
        Node* temp = head;

        do{
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};

int main(){
    CircularList cl;
    cl.insertLast(5);
    cl.insertLast(15);
    cl.insertLast(25);
    cl.insertLast(35);
    cout << "Size of Circular Linked List = " << cl.size();
    return 0;
}
