#include<iostream>
using namespace std;

int arr[100];
int size;
int num;
int index;

void cons(void);
void display(void);
void found(void);

int main(){
    cons();
    found();
    return 0;
}

void cons(void){
    cout<<"enter the size of array :"<<endl;
    cin>>size;
    cout<<"enter the values to the sorted array : "<<endl;
    for(int i=0;i<size;i++){
        cout<<"value at "<<i+1<<" : ";
        cin>>arr[i];
    }
    display();
}

void display(void){
    cout<<"the array is : "<<endl;
    cout<<"[";
    for(int i=0;i<size;i++){
    cout<<" "<<arr[i];
    }
    cout<<"]"<<endl;
}

void found(void){
    cout<<"enter the value to find :"<<endl;
    cin>>num;
    int a,b;
    a = 0;
    b = size-1;
    int mid = (a+b)/2;
    while(arr[mid]!=num){
        if(arr[mid]<num){
            a = mid;
            mid = (a+b)/2;
        }
        else{
            b = mid;
            mid = (a+b)/2;
        }
    }
    cout<<"the no. at "<<mid+1;
}