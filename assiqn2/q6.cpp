#include<iostream>
using namespace std;

/*
6) Write a program to implement the following operations on a Sparse Matrix, 
assuming the matrix is represented using a triplet. 
(a) Transpose of a matrix. 
(b) Addition of two matrices. 
(c) Multiplication of two matrices. 
*/

int main(){
int non_zero = 5;
const int row_count = 5;
const int column_count = 3;
int sp_mtrix[5][3] = {
    {0 , 0 , 9},
    {1 , 1 , 8},
    {2 , 0 , 5},
    {2 , 1 , 3},
    {3 , 0 , 9}
};

// Transpose of a matrix
int trans[4][3];
for(int i=0;i<row_count;i++){
trans[i][0] = sp_mtrix[i][1];
trans[i][1] = sp_mtrix[i][0];
trans[i][2] = sp_mtrix[i][2];
}
for(int i = 0;i<row_count;i++){
    for(int j=0;j<column_count;j++){
        cout<<trans[i][j];
    }
    cout<<endl;
}
    return 0;
}