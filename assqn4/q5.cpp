#include<iostream>
#include<queue>
using namespace std;

void first_non_repeat(string str){
    queue<char> q;
    int freq[26] = {};

    for(char c: str){
        freq[c - 'a']++;
        q.push(c);
    
    while(!q.empty() && freq[q.front() - 'a'] > 1)
    q.pop();
    if(q.empty())cout<<"-1";
    else cout<<q.front()<<" ";
    }
}

int main(){
string input = "aabc";
first_non_repeat(input);
    return 0;
}
