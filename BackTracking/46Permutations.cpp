#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given an array nums of distinct integers, 
// return all the possible permutations. 
// You can return the answer in any order.


vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()) result.push_back(path);
    for(int i = 0; i < nums.size(); i++){
        if(used[i] == true) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        used[i] = false;
        path.pop_back();
    }

}

void permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
}


int main(){
    vector<int> nums = {1,2,3};
    permute(nums);


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