#include<iostream>
using namespace std;

int arr[100][100];
int trans[100][100];
int row_size,column_size;

void crete(void);
void disply_arr(void);
void disply_trans(void);
void transpose(void);


int main(){
crete();
transpose();
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
    disply_arr();
}

void disply_arr(){
    cout<<"the matrix is : "<<endl;
    for(int i = 0;i<row_size;i++){
        for(int j=0 ; j<column_size;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disply_trans(){
    cout<<"the matrix is : "<<endl;
    for(int i = 0;i<column_size;i++){
        for(int j=0 ; j<row_size;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void transpose(void){
    for(int i=0;i<row_size;i++){
        for(int j=0;j<column_size;j++){
            trans[j][i] = arr[i][j];
        }
    }
    disply_trans();
}