#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Given an integer array nums, return all the different possible 
// non-decreasing subsequences of the given array with at least two elements. 
// You may return the answer in any order.


vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    if(path.size() > 1) result.push_back(path);
    unordered_set<int> uset;
    for(int i = startIndex; i < nums.size(); i++){
        if(!path.empty() && nums[i] < path.back()) continue;
        if(uset.find(nums[i]) != uset.end()) continue;
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(nums, i+1);
        path.pop_back();
    }
  
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    backtracking(nums, 0);
    return result;
}


int main(){
    vector<int> nums = {4,6,7,7};
    result = findSubsequences(nums);


    for(auto res : result){
        bool first = true;
        cout<<'[';
        for(int i : res) {
            if(!first) cout<<" ";
            cout<<i;
            first = false;
        }
        cout<<"] ";
    }
    return 0;
}