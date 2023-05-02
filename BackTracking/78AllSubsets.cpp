#include<iostream>
#include<vector>
using namespace std;

// Given an integer array nums of unique elements, return all possible 
// subsets(the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.


vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    result.push_back(path);
    if(startIndex >= nums.size()) return;
    for(int i = startIndex; i< nums.size(); i++){
        path.push_back(nums[i]);
        backtracking(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    backtracking(nums, 0);
    return result;
}


int main(){
    vector<int> nums = {1,2,3};
    subsets(nums);


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