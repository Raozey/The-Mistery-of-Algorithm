#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
/*
// 定义大小顶堆中的cmp, 大于是小顶堆，小于是大顶堆
// 定义闭包函数不用取地址
auto cmp = [&](const pair<int,int> a, const pair<int,int> b){
    return a.second > b.second;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

//外部定义函数需要取地址
bool cmp (const pair<int,int> a, const pair<int,int> b){
    return a.second > b.second;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> que(&cmp);

//定义类或者结构体需要设置为public，不需要decltype
class cmp{
    public:
    bool operator()(const pair<int,int> a, const pair<int,int> b){
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> umap;
    vector<int> result;
    for(int i : nums) umap[i]++;

    auto cmp = [&](const pair<int,int> a, const pair<int,int> b){
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

    for(auto it = umap.begin(); it != umap.end(); it++){
        que.push(*it);
        if(que.size() > k) que.pop();
    }

    for(int i = k - 1; i >= 0; i--){
        result.push_back(que.top().first);
        que.pop();
    }
    return result;
}



int main(){
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> res = topKFrequent(nums, 2);
    for(int i : res) cout<<i<<" ";
    return 0;
}