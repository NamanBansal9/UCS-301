#include<iostream>
using namespace std;

int main(){
int A[100][100];
int size;
cout<<"enter no. of size : "<<endl;
cin>>size;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(i<=j){
        cout<<"enter value : "<<i+1<<"*"<<j+1<<" ";
        cin>>A[i][j];
        A[j][i] = A[i][j];
        }
    }
}
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        cout<<A[i][j];
    }
    cout<<endl;
}
    return 0;
}
