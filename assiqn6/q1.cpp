#include<iostream>
using namespace std;

class DNode{
    public:
        int data;
        DNode *prev,*next;

        DNode(int val){
            data = val;
            prev = next = nullptr;
        }
};
class DoublyList{
    DNode* head;

    public:
        DoublyList(){
            head = nullptr;
        }
        void insertFirst(int x){
            DNode* n = new DNode(x);
            n->next = head;
            if(head) head->prev = n;
            head = n;
        }
        void insertLast(int x){
            DNode* n = new DNode(x);
            if(!head){
                head = n;
                return ;
            }
            DNode* t = head;
            while(t->next) t = t->next;
            t->next = n;
            n->prev = t;
        }
        void insertAfter(int key, int x){
            DNode* t = head;
            while(t && t->data != key) t = t->next;
            if(!t){
                cout<<"Node not found"<<endl;
                return ;
            } 
            DNode* n = new DNode(x);
            n->next = t->next;
            n->prev = t;
            if(t->next) t->next->prev = n;
            t->next = n;
        }
        void insertBefore(int key, int x){
            if(head && head->data == key){    
            insertFirst(x);
            return ;
            }
            DNode* t = head;
            while(t && t->data != key)t = t->next;
            if(!t){
                cout<<"node not found"<<endl;
                return ;
            }
            DNode* n = new DNode(x);
            n->next = t;
            n->prev = t->prev;
            t->prev->next = n;
            t->prev = n;
        }
        void deleteNode(int key){
            if(!head) return ;
            DNode* t = head;
            if(t->data == key){
                head = t->next;
                if(head) head->prev = nullptr;
                delete t;
                return ;
            }
            while(t && t->data != key) t = t->next;
            if(!t) {
                cout<<"Node not found";
                return ;
            }
            if(t->next) t->next->prev = t->prev;
            t->prev->next = t->next;
            delete t;
        }
        void search(int key){
            DNode* t = head;
            int pos = 1;
            while(t){
                if(t->data == key){
                    cout<<"found at position"<<pos<<endl;
                    return ;
                }
                pos++;
                t = t->next;
            }
            cout<<"Node not found"<<endl;
        }
        void display(){
            DNode* t = head;
            cout<<"DLL : ";
            while(t){
                cout<<t->data<<" <-> ";
                t = t->next;
            }
            cout<<"NULL"<<endl;
        }
};

class CircularNode{
    public:
        int data;
        CircularNode* next;

        CircularNode(int val){
            data = val;
            next = nullptr;
        }
};
class CircularList{
        CircularNode* head;
    public:
        CircularList(){
            head = nullptr;
        }
        void insertFirst(int x){
            CircularNode* n = new CircularNode(x);
            if(!head){
                head = n;
                n->next = head;
                return ;
            }
            CircularNode* t = head;
            while(t->next != head) t = t->next;
            n->next = head;
            t->next = n;
            head = n;
        }
        void insertLast(int x){
            if(!head){
                insertFirst(x);
                return;
            }
            CircularNode* n = new CircularNode(x);
            CircularNode* t = head;
            while(t->next != head) t = t->next;
            t->next = n;
            n->next = head; 
        }
        void insertAfter(int key, int x){
            if(!head) return ;
            CircularNode* t = head;

            do{
                if(t->data == key){
                    CircularNode* n = new CircularNode(x);
                    n->next = t->next;
                    t->next = n;
                    return ;
                }
                t = t->next;
            }while(t != head);
            cout<<"Node not found"<<endl;
        }
        void deleteNode(int key){
            if(!head) return ;
            CircularNode *t = head, *prev = nullptr;
            if(head->data == key){
                if(head->next == head){
                    delete head;
                    head = nullptr;
                    return ;
                }
                while(t->next != head) t = t->next;
                t->next = head->next;
                delete head;
                head = t->next;
                return ;
            }
            do{
                prev = t;
                t = t->next;
                if(t->data == key){
                    prev->next = t->next;
                    delete t;
                    return ;
                }
            }while(t != head);
            cout<<"Node not found"<<endl;
        }
        void search(int key){
            if(!head) return ;
            CircularNode* t = head;
            int pos = 1;
            do{
                if(t->data == key){
                    cout<<"Found at position"<<pos<<endl;
                    return ;
                }
                pos++;
                t = t->next;
            }while(t != head);
            cout<<"Node not found"<<endl;
        }
        void display(){
            if(!head){
                cout<<"CLL empty"<<endl;
                return ;
            }
            CircularNode* t = head;
            cout<<"CLL : ";
            do{
                cout<<t->data<<" -> ";
                t = t->next;
            }while(t != head);
            cout<<"(head)"<<endl;
        }
};

int main(){
DoublyList dll;
CircularList cll;
int listType, ch, x, key;

while(true){
    cout<<"1.Doubly Linked List"<<endl<<"2.Circular Linked List"<<endl<<"3.exit"<<"choice : "<<endl;
    cin>>listType;
    if(listType == 3) break;
    cout<<"1.Insert First\n2.Insert last\n3.Insert After\n4.Insert Before\n5.Delete Node\n6.Search\n7.Display\n8.Back"<<endl;
    while(true){
        cout<<"enter option: ";
        cin>>ch;
        if(ch == 8) break;
        switch(ch){
            case 1:
                cout<<"enter value: ";cin>>x;
                (listType==1?dll.insertFirst(x):cll.insertFirst(x)); break;

                case 2: cout << "Enter value: "; cin >> x;
                        (listType==1?dll.insertLast(x):cll.insertLast(x)); break;

                case 3: cout<<"Enter key and value: "; cin>>key>>x;
                        (listType==1?dll.insertAfter(key,x):cll.insertAfter(key,x)); break;

                case 4:
                    if (listType==1) {
                        cout<<"Enter key and value: "; cin>>key>>x;
                        dll.insertBefore(key,x);
                    } else cout<<"Insert BEFORE not used in CLL\n";
                    break;

                case 5: cout<<"Enter value to delete: "; cin>>key;
                        (listType==1?dll.deleteNode(key):cll.deleteNode(key)); break;

                case 6: cout<<"Enter value to search: "; cin>>key;
                        (listType==1?dll.search(key):cll.search(key)); break;

                case 7: (listType==1?dll.display():cll.display()); break;

                default : cout<<"Invalid"<<endl;
        }
    }
}
    return 0;
}
