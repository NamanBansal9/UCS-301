#include<iostream>
using namespace std;

int A[100][100];
int B[100][100];
int mul[100][100];
int row_size,column_size,sub_size;

void crete(int);
void disply(void);
void multi(void);

int main(){
    cout<<"let's crete first matrix : "<<endl;
    cout<<"enter the no. of rows and columns : "<<endl;
    cin>>row_size>>sub_size;
    crete(1) ;
    int check;
    cout<<"Now crete second matrix : "<<endl;
    cout<<"enter the no of rows and columns : "<<endl;
    cin>>check>>column_size;
    if(sub_size != check){
        cout<<"wrong size of matrix";
        return 0;
    }
    else 
    crete(2);
    cout<<"the net matrix multiplied is : "<<endl;
    multi();

    return 0;
}

void crete(int n){
if(n==1){
    cout<<"enter the value's for first matrix : "<<endl;
    for(int i=0;i<row_size;i++){
        for(int j=0;j<sub_size;j++){
            cout<<"value at "<<i+1<<" * "<<j+1<<" is : ";
            cin>>A[i][j];
        }
    }
}
else if(n==2){
    cout<<"enter the value's for second matrix : "<<endl;
    for(int i=0;i<sub_size;i++){
        for(int j=0;j<column_size;j++){
            cout<<"value at "<<i+1<<" * "<<j+1<<" is : ";
            cin>>B[i][j];
        }
    }
}
}

void multi(void){
for(int i=0;i<row_size;i++){
    for(int j=0;j<column_size;j++){
        mul[i][j] = 0;
        for(int k = 0;k<sub_size;k++){
            mul[i][j]= mul[i][j] + (A[i][k] * B[k][j]);
        }
    }
}
disply();
}

void disply(void){
    for(int i=0;i<row_size;i++){
        for(int j=0;j<column_size;j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }
}