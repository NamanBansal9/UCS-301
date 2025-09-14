#include<iostream>
using namespace std;

class stack{
    int arr[100];
    int top;
    int capacity;
    public:
    stack(int size){
        top = -1;
        capacity = size;
    }
    bool isempty(){
        return top==-1;
    }
    bool isfull(){
        return top == capacity -1;
    }
    void pus(int n){
        if(isfull()){
            cout<<"sorry stack is over floaded"<<endl;
            return;
        }
        arr[++top] = n;
        cout<<n<<" pused into stack"<<endl;
    }
    int pop(){
        if(isempty()){
            cout<<"stack is under fload"<<endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    void display(void){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        cout<<"stack (top to bottom) :"<<endl;
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
int size;
cout<<"enter size of stack : "<<endl;
cin>>size;
stack st(size);
int k=1;
int n;
do{
    cout<<"----- Stack Menu -----"
        <<endl
        <<"1.pus"<<endl
        <<"2.pop"<<endl
        <<"3.isempty"<<endl
        <<"4.is full"<<endl
        <<"5.peek"<<endl
        <<"6.display"<<endl
        <<"7.exit"<<endl;
        cout<<"enter coice"<<endl;
        cin>>n;


switch (n){
    case 1:
    int val;
        cout<<"enter value to pus"<<endl;
        cin>>val;
        st.pus(val);
        break;
    case 2:
        cout<<"popped value : "<<st.pop()<<endl;
        break;
    case 3:
        cout<<"stack is empty :"<<st.isempty()<<endl;
        break;
    case 4:
        cout<<"stack is full :"<<st.isfull()<<endl;
        break;
    case 5:
        cout<<"val at peek : "<<st.peek()<<endl;
        break;
    case 6:
        st.display();
        break;
    case 7:
        cout<<"Exit...."<<endl;
        k = 0;
        break;
    default:
        cout<<"invalid coice so Exit...."<<endl;
        k = 0;
        break;
};
}while (k==1);

    return 0;
}
