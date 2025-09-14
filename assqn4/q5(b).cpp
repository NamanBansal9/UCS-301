#include<iostream>
#include<queue>
using namespace std;

class stack_two_queue{
    queue<int> q;
    public:
        void pus(int val){
            int size = q.size();
            q.push(val);
            while(size--){
                q.push(q.front());
                q.pop();
            }
        }
        void pop(){
            if(q.empty()){
                cout<<"stack is empty"<<endl;
                return;
            }
            cout<<"popped val : "<<q.front()<<endl;
            q.pop();
        }
        void top(){
            if(q.empty()){
                cout<<"stack is empty.."<<endl;
                return ;
            }
            cout<<"value at top : "<<q.front()<<endl;
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
