#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;



class MyQueue {
public:
    MyQueue() {}
    void push(int x) {st1.push(x);}
    bool empty() {return st1.empty();}
    int pop() {
        // 把st1全部压入到st2,然后弹出一个元素在压回st1
        while(!st1.empty()){
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }
        int res = st2.top();
        st2.pop();
        while(!st2.empty()){
            int x = st2.top();
            st2.pop();
            st1.push(x);
        }
        return res;
    }
    int peek() {
                while(!st1.empty()){
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }
        int res = st2.top();
        while(!st2.empty()){
            int x = st2.top();
            st2.pop();
            st1.push(x);
        }
        return res;
    }
private:
    stack<int> st1;
    stack<int> st2;
};

class MyQueue2 {
public:
    MyQueue() {}
    void push(int x) {}
    bool empty() {}
    int pop() {

    }
    int peek() {

    }
private:
    stack<int> stIn;
    stack<int> stOut;
};




int main(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue->peek(); // return 1
    myQueue->pop(); // return 1, queue is [2]
    myQueue->empty(); // return false
    return 0;
}