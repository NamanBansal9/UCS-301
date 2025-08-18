#include<iostream>
using namespace std;

int arr[100][100];
int trans[100][100];
int row_size,column_size;

void crete(void);
void disply(void);
void transpose(void);
void row_sum(void);
void column_sum(void);

int main(){
crete();
int n;
cout<<"enter 1 for row wise sum and 2 for column wise : "<<endl;
cin>>n;
if(n==1){
    row_sum();
}
else if(n == 2){
    column_sum();
}

return 0;
}

void crete(void){
    cout<<"enter the size of matirx as row and column no. : "<<endl;
    cin>>row_size>>column_size;
    cout<<"enter the elements for matrix : "<<endl;
    for(int i=0;i<row_size;i++){
        for(int j=0;j<column_size;j++){
            cout<<"value for "<<i+1<<" * "<<j+1<<" : ";
            cin>>arr[i][j];
        }
    }
    disply();
}

void disply(void){
    cout<<"the matrix is : "<<endl;
    for(int i = 0;i<row_size;i++){
        for(int j=0 ; j<column_size;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void row_sum(void){
cout<<"the row wise sum is : "<<endl;
cout<<"[ ";
for(int i=0;i<row_size;i++){
    int sum = 0;
    for(int j=0 ;j<column_size;j++){
        sum = sum + arr[i][j];
    }
    cout<<sum<<" ";
}
cout<<"]"<<endl;
}

void column_sum(void){
transpose();
cout<<"the column wise sum is : "<<endl;
cout<<"[ ";
for(int i=0;i<row_size;i++){
    int sum = 0;
    for(int j=0 ;j<column_size;j++){
        sum = sum + trans[i][j];
    }
    cout<<sum<<" ";
}
cout<<"]"<<endl;
}

void transpose(void){
    for(int i=0;i<row_size;i++){
        for(int j=0;j<column_size;j++){
            trans[j][i] = arr[i][j];
        }
    }
}