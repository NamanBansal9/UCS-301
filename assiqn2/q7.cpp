#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1,2,3,8,9,5,4,2,1,3,6,5};
    vector<pair<int,int>> kp;
    for(int i = 0;i<11;i++){
        for(int j = i+1;j<12;j++){
            if(arr[i]>arr[j]){
                kp.push_back({arr[i],arr[j]});
            }
        }
    }
for(pair<int,int> x : kp){
    cout<<"{"<<x.first<<" , "<<x.second<<"}"<<endl;
}
return 0;
}