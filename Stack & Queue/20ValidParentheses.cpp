#include <iostream>
#include <stack>
#include <string>
using namespace std;

//用for循环实现
bool isValid(string s) {
    stack<char> st;
    int size = s.size();
    for (int i = 0; i < size; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

        else{
            if (s[i] == '}'){
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
            }
            if (s[i] == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
            }
            if (s[i] == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
            }
        }
    }
    if (st.empty()) return true;
    else return false;
}


//用switch实现
bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
        switch (c) {
            default:
                break;
            case '(':
                stk.push(')');
                break;
            case '{':
                stk.push('}');
                break;
            case '[':
                stk.push(']');
                break;
            case ')':
                if (stk.empty() || stk.top() != ')')  return false;
                stk.pop();
                break;
            case '}':
                if (stk.empty() || stk.top() != '}')  return false;
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top() != ']')  return false;
                stk.pop();
                break;
        }
    }
    return stk.empty();
}



int main() {
    string s = "()[]{}";
    bool result = isValid(s);
    cout << "Result: " << result << endl; // 应该输出 1

    s = "(]";
    result = isValid(s);
    cout << "Result: " << result << endl; // 应该输出 0

    s = "([)]";
    result = isValid(s);
    cout << "Result: " << result << endl; // 应该输出 0

    s = "{[]}";
    result = isValid(s);
    cout << "Result: " << result << endl; // 应该输出 1

    return 0;
}
