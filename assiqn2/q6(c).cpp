#include<iostream>
using namespace std;

int main(){
    int A[5][3] = {
        {3,3,4},
        {0,0,9},
        {0,1,6},
        {1,1,3},
        {2,2,8}
    };
    int B[5][3]={
        {3,3,4},
        {0,1,5},
        {1,2,6},
        {2,0,7},
        {2,2,8}
    };
    if(A[0][1] != B[0][0]){
        cout<<"dimension error"<<endl;
        return 0;
    }
    int temp[100][100] = {0};
    int row = A[0][0];
    int column = B[0][1];
    int common = A[0][1];
    for(int i = 0;i<A[0][2];i++){
        for(int j = 0;j<B[0][2];j++){
            if(A[i][1] == B[j][0]){
                int n = A[i][0];
                int m = B[j][1];
                temp[n][m] += A[i][2]*B[j][2];
            }
        }
    }
    int k=1;
    int re[10][3];
    for(int i = 0;i<row;i++){
        for(int j = 0;j<column;j++){
            if((temp[i][j] != 0)){
                re[k][0] = i;
                re[k][1] = j;
                re[k][2] = temp[i][j];
                k++;
            }
        }
    }
    re[0][0] = row;
    re[0][1] = column;
    re[0][2] = k-1;
    for(int i = 0;i<=re[0][2];i++){
        cout<<re[i][0]<<" "<<re[i][1]<<" "<<re[i][2]<<endl;
    }

    return 0;
}
