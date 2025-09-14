#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
string str = "Lol";
stack<char> st;
for(char c : str){
    st.push(c);
}
string rev;
while(!(st.empty())){
    rev = rev + st.top();
    st.pop();
}
cout<<rev<<endl;
    return 0;
}
