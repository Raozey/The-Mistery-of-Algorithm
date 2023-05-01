#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

class myqueue
{
private:
    deque<int> que;
public:
    int front() {return que.front();}
    void push(int x){
        while(!que.empty() && x > que.back()) que.pop_back();
        que.push_back(x);
    }
    void pop(int x){
        if(!que.empty() && que.front() == x) que.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    vector<int> result;
    myqueue que;
    for(int i = 0; i < k; i++) que.push(nums[i]);
    result.push_back(que.front());
    for(int i = k; i < nums.size(); i++){
        que.pop(nums[i-k]);
        que.push(nums[i]);
        result.push_back(que.front());
    }
    return result;
}


int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res = maxSlidingWindow(nums, 3);
    for(int i : res) cout<<i<<" "; //3,3,5,5,6,7
    return 0;
}
