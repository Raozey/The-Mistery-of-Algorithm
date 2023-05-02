#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given an integer array nums of unique elements, return all possible 
// subsets(the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.


vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex, vector<int> used){
    result.push_back(path);
    if(startIndex >= nums.size()) return;
    for(int i = startIndex; i< nums.size(); i++){
        if( i > 0 && nums[i] == nums[i-1] && used[i-1] == 0) continue;
        path.push_back(nums[i]);
        used[i] = 1;
        backtracking(nums, i+1, used);
        used[i] = 0;
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> used(nums.size(), 0);
    sort(nums.begin(), nums.end());
    backtracking(nums, 0, used);
    return result;
}


int main(){
    vector<int> nums = {1,2,2};
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