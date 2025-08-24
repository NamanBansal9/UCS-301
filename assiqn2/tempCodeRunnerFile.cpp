#include<iostream>
using namespace std;
/* 
Given an array of n-1 distinct integers in the range of 1 to n, find the missing number 
in it in a Sorted Array 
(a) Linear time 
(b) Using binary search
*/
int arr[5] = {1,2,3,4,6};
void linear(void);
void binary(void);
int main(){
    linear();
    binary();
    return 0;
}
void linear(void){
    cout<<"linear : "<<endl;
    for(int i = 0;i<5;i++){
        if(arr[i] != i+1){
            cout<<"value : "<<i+1<<" is missing.."<<endl;
            break;
        }
    }
}
void binary(void){
    cout<<"binary : "<<endl;
    int a,b,m;
    a = 0;
    b = 5;
    m = (a+b)/2;
    // int k = 0;
    if(arr[b-1] == b){
        cout<<"No missing value..";
        return;
    }
    while((arr[m] != m+1) && (arr[m-1] == m) && (arr[m+1] == m+3)){
        if(arr[m] == m+1){
            a = m;
            m = (a+b)/2;
        }
        else if(arr[m] > m+1){
            b = m;
            m = (a+b)/2;
        }
    }
    cout<<"missing value : "<<m+1<<endl;
}