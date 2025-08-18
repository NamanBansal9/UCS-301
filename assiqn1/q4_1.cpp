#include<iostream>
using namespace std;



int arr[100];
int size = 0;
int fd = 0;

void crete(int arr[100],int);
void disply(void);


int main(){
    cout<<"enter the size of the array : "<<endl;
    cin>>size;
    cout<<"now the array elements : "<<endl;
    crete(arr,size);
    cout<<"the array written by you : "<<endl;
    disply();

    for(int i=0,j=size-1;(i<size/2)&&(j>size/2);i++,j--){
        fd = arr[i];
        arr[i] = arr[j];
        arr[j] = fd ;
    }
    cout<<"the reversed array is : "<<endl;
    disply();
    return 0;
}

void crete(int arr[100],int size){
    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" no. :"<<endl;
        cin>>arr[i];
    };
}

void disply(){
    cout<<"the array is : [ ";
    for(int i=0;i<size;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<"]"<<endl;
}