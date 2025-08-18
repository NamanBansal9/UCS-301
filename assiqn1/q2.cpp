#include<iostream>
using namespace std;

int arr[100];
int size = 0;
int fd = 0;

void crete(int arr[100],int);
void disply(void);
void delte(int);
void linear_search(int);

int main(){
    cout<<"enter the size of the array : "<<endl;
    cin>>size;
    cout<<"now the array elements : "<<endl;
    crete(arr,size);
    cout<<"the array written by you : "<<endl;
    disply();
    for(int i=0;i<size;i++){
        int initial = arr[i];
        for(int j=i+1;j<size;j++){
            if(arr[j] == initial){
                delte(arr[j]);
                fd = 1;
                i--;
            }
        }
    }
    if(fd == 1){
        cout<<"the array with unique no. of elements : "<<endl;
    }
    else if(fd == 0){
        cout<<"the array does not contain any duplicate so. the array is :"<<endl;
    }
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

void delte(int num){ 
    for(int i = num ; i<size-1 ;i++){
        arr[i] = arr[i+1];
    }
    size-- ;
}