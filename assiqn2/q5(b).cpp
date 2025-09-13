#include<iostream>
using namespace std;

int main(){
int A[100][100];
int size;
cout<<"enter no. of size : "<<endl;
cin>>size;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(i==j || ((i-j)==1) || ((j-i)==1)){
        cout<<"enter value : "<<i+1<<"*"<<j+1<<" ";
        cin>>A[i][j];
        }
        else A[i][j] = 0;
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
