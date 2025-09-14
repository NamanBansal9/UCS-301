#include<iostream>
using namespace std;

class circular_queue{
    int arr[100];
    int front,rear,capacity;

    public : 
        circular_queue(int size){
            capacity = size;
            rear = front = -1;
        }
    bool is_empty(){
        return front == -1;
    }
    bool is_full(){
        return (rear+1)%capacity == front;
    }
    void in_queue(int val){
        if(is_full()){
            cout<<"queue is full"<<endl;
            return ;
        }
        if(is_empty()){
            rear = front = 0;
        }else{
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
        cout<<val<<" is stored in queue"<<endl; 
    }
    void out_queue(){
        if(is_empty()){
            cout<<"queue is empty"<<endl;
            return ;
        }
        cout<<"queue values : "<<arr[front]<<endl;
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front+1)%capacity ;
        }
    }
    void peek(){
        if(is_empty()){
            cout<<"queue is empty"<<endl;
        }
        else cout<<"front element : "<<arr[front]<<endl; 
    }
    void display(){
        if(is_empty()){
            cout<<"queue is empty"<<endl;
            return ;
        }
        cout<<"queue values : "<<endl;
        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear) break;
            i = (i+1)% capacity;
        }
        cout<<endl;
    }
};

int main(){

    int size;
    cout << "Enter circular queue size: ";
    cin >> size;
    circular_queue q(size);
    int coice, val;
    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cin >> coice;
        switch (coice) {
            case 1: cout << "Enter value: "; cin >> val; q.in_queue(val); break;
            case 2: q.out_queue(); break;
            case 3: q.peek(); break;
            case 4: cout << (q.is_empty() ? "Yes\n" : "No\n"); break;
            case 5: cout << (q.is_full() ? "Yes\n" : "No\n"); break;
            case 6: q.display(); break;
        }
    }while(coice != 7);
    return 0;
}
