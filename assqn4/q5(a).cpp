#include<iostream>
#include<queue>
using namespace std;

class stack_two_queue{
    queue<int> q1,q2;
    public:
        void pus(int val){
            q2.push(val);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        void pop(){
            if(q1.empty()){
                cout<<"stack is empty"<<endl;
                return;
            }
            cout<<"popped val : "<<q1.front()<<endl;
            q1.pop();
        }
        void top(){
            if(q1.empty()){
                cout<<"stack is empty.."<<endl;
                return ;
            }
            cout<<"value at top : "<<q1.front()<<endl;
        }
};

int main(){
stack_two_queue st;
st.pus(9);
st.pus(8);
st.pus(5);
st.top();
st.pop();
st.top();
st.pop();
st.top();
    return 0;
}
