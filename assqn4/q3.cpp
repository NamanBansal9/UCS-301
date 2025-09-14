#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int>& q){
    if(q.size() %2 != 0){
        cout<<"queue len must be even.."<<endl;
        return ;
    }
    int kd = q.size() /2;
    queue<int> kd_queue ;
    for(int i=0;i<kd;i++){
        kd_queue.push(q.front());
        q.pop();
    }
    while(!kd_queue.empty()){
        q.push(kd_queue.front());
        kd_queue.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
queue<int> q;
int input[] = {4,7,11,20,5,9};
for(int val : input){
    q.push(val);
}
interleave(q);
cout<<"interleaved queue : "<<endl;
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
    return 0;
}
