#include <iostream>
using namespace std;

class Node{
public:
    char data;
    Node* prev;
    Node* next;

    Node(char ch){
        data = ch;
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

    void insertLast(char ch){
        Node* n = new Node(ch);
        if(!head){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next) 
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    bool isPalindrome(){
        if(!head) return true; 
        
        Node* left = head;
        Node* right = head;

        while(right->next)
            right = right->next;

        while(left != right && right->next != left){
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DoublyLinkedList dl;
    string s;
    cout << "Enter characters (string): ";
    cin >> s;
    for(char c : s)
        dl.insertLast(c);
    if(dl.isPalindrome())
        cout << "The list is a Palindrome.";
    else
        cout << "The list is NOT a Palindrome.";
    return 0;
}
