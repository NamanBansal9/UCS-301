#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

string infix_to_postfix(string infix){
    stack<char> st;
    string result ;
    for(char c : infix){
        if(isalnum(c))
            result = result + c;
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!(st.empty()) && st.top() !='('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!(st.empty()) && precedence(st.top()) >= precedence(c)){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!(st.empty())){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){
string infix = "a+b*(c-d)";
cout<<"Postfix : "<<infix_to_postfix(infix) <<endl;
    return 0;
}
