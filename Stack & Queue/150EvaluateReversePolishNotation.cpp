#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string s : tokens){
        if(s == "+"){
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            st.push(num1 + num2);
        }
        else if(s == "-"){
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            st.push(num2 - num1);
        }

        else if(s == "*"){
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            st.push(num1 * num2);
        }
        else if(s == "/"){
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            st.push(num2 / num1);
        }
        else st.push(stoi(s));
    }
    return st.top();
}





int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    int res = evalRPN(tokens);
    cout<<"result: "<<res<<endl; //((2 + 1) * 3) = 9
    return 0;
}