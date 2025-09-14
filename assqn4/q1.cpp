#include<iostream>
using namespace std;

class queue{
    int arr[100];
    int front,rear,capacity;
    public : 
        queue(int size){
            capacity = size;
            front = 0;
            rear = -1;
        }
        bool isfull(){
            return rear == capacity -1;
        }
        bool isempty(){
            return rear < front ;
        }
        void in_queue(int val){
            if(isfull()){
                cout<<"sorry queue is full "<<endl;
                return ;
            }
            arr[++rear] = val;
            cout<<val<<"is stored in queue "<<endl;
        }
        void out_queue(){
            if(isempty()){
                cout<<"queue is empty "<<endl;
                return ;
            }
            cout<<"de - queue : "<<arr[front++]<<endl;
        }
        void peek(){
            if(isempty()){
                cout<<"queue is empty "<<endl;
                return ;
            } else{
                cout<<"front element : "<<arr[front]<<endl;
            }
        }
        void display(){
            if(isempty()){
                cout<<"queue is empty "<<endl;
                return ;
            }
            cout<<"queue is : "<<endl;
            for(int i = front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }
};

int main(){
    int size;
    cout<<"enter size : "<<endl;
    cin>>size;
    queue q(size);
    int coice , val;
    do{
        cout<<"----- queue Menu -----"<<endl
            <<"1. in queue "<<endl
            <<"2. out queue"<<endl
            <<"3. Peek "<<endl
            <<"4. is empty"<<endl
            <<"5. is full"<<endl
            <<"6. display"<<endl
            <<"7. exit "<<endl;
        cin>>coice;
        switch(coice){
            case 1:
                cout<<"enter value : "<<endl;
                cin>>val;
                q.in_queue(val);
                break;
            case 2:
                q.out_queue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.isempty();
                break;
            case 5:
                q.isfull();
                break;
            case 6:
                q.display();
                break;
        }
    }while(coice != 7);
    
    return 0;
}
