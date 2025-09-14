#include<iostream>
using namespace std;

int main(){
int arr[] = {9,8,5,6,4,3,2,9,5,8,1};
int n = sizeof(arr)/sizeof(arr[0]);
int re[20];
int count=0;
int run = 1;
for(int i = 0;i<n;i++){
    run = 1;
for(int j=i+1;j<n;j++){
    if(arr[j] == arr[i]){
        run = 0;
    }
}
if(run == 1){
    re[count] = arr[i];
    count++;
    
}
}
cout << count<<endl;
for(int i=0;i<count;i++){
    cout<<re[i];
}
    return 0;
}
