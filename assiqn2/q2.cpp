#include<iostream>
using namespace std;

int main(){
    int arr[7] = {64,34,25,12,22,11,90};
    int n;
    for(int i = 0;i<7;i++){
        int c = 1;
        for(int j = 0;j<(7-i);j++){
            if(arr[j] > arr[j+1]){
                n = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = n;
                c = 0;
            }
        }
        if(c == 1){
            break;
        }
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}