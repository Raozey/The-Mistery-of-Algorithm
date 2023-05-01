#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;




class MyStack {
public:
    MyStack() {}
    
    void push(int x) { que1.push(x); }
    
    int pop() {
        int size = que1.size();
        int out = size - 1;
        size--;
        while(size--){
            int x = que1.front();
            que1.pop();
            que2.push(x);
        }
        int res = que1.front();
        que1.pop();
        while(out--){
            int x = que2.front();
            que2.pop();
            que1.push(x);
        }
        return res;
    }
    
    int top() {
        int res = this->pop();
        que1.push(res);
        return res;
    }
    
    bool empty() { return que1.empty();}
private:
    queue<int> que1;
    queue<int> que2;
};

int main(){
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    myStack->top(); // return 2
    myStack->pop(); // return 2
    myStack->empty(); // return False
    return 0;
}