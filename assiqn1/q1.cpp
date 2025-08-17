#include<iostream>
using namespace std;

int arr[100];
int size = 0;
int run = 1;
int fd;

void crete(int arr[100],int);
void disply(void);
void insert(void);
void delte(int);
void linear_search(int);

int main(){

    while(run == 1){
        cout<<"<< Menu Driven Proram >>"<<endl;
        cout<<" ------ Menu ------"<<endl;
        cout<<"1. for create"
            <<endl
            <<"2. for Display"
            <<endl
            <<"3. for insert"
            <<endl
            <<"4. for Delete"
            <<endl
            <<"5. for linear search"
            <<endl
            <<"6. for Exit"
            <<endl;
        int option = 6;
        cout<<"enter the choice : ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"enter the size of array :"<<endl;
            cin>>size;
            crete(arr,size);
            break;
        case 2:
            disply();
            break;
        case 3:
            insert();
            break;
        case 4:
            int num;
            cout<<"enter the no. to delete : "<<endl;
            cin>>num;
            delte(num);
            break;
        case 5:
            int no;
            cout<<"enter the value to find index : "<<endl;
            cin>>no;
            linear_search(no);
            cout<<"the element "<<no<<"is found at : "<<fd<<endl;
            break;
        case 6:
            run = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

void crete(int arr[100],int size){
    for(int i=0;i<size;i++){
        cout<<"enter the "<<i+1<<" no. :"<<endl;
        cin>>arr[i];
    };
    disply();
}

void disply(){
    cout<<"the array is : [ ";
    for(int i=0;i<size;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<"]"<<endl;
}

void insert(){
    int index;
    int value;
    cout<<"enter the value and index : "<<endl;
    cin>>value>>index;cout<<endl;
    for(int i=(size);i>=index;i--){
        arr[i]=arr[i-1];
    }
    arr[index-1] = value;
    size++;
    disply();
}

void delte(int num){
    int index; 
    linear_search(num);
    for(int i = fd ; i<size-1 ;i++){
        arr[i] = arr[i+1];
    }
    size-- ;
    disply();
}

void linear_search(int no){
for(int i=0;i<size;i++){
    if(arr[i]==no){
        fd = i;
        break;
    }
}
}