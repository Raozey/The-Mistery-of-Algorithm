#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


string removeDuplicates(string s) {
    stack<char> st;
    for(char c : s){
        if(!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    string res = "";
    while(!st.empty()) {
        char c = st.top();
        st.pop();
        res.push_back(c);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s = "abbacaa";
    s = removeDuplicates(s);
    cout<<"result: "<<s<<endl;
    return 0;
}