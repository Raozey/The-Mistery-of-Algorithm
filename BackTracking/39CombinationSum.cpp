#include<iostream>
#include<vector>
using namespace std;

// Given an array of distinct integers candidates and a target integer target, 
// return a list of all unique combinations of candidates where the chosen numbers sum to target. 
// You may return the combinations in any order.


vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& candidates, int target, int index,int sum){
    if(sum > target) return;
    if(sum == target){
        result.push_back(path);
        return;
    }
    for(int i = index; i < candidates.size(); i++){
        sum+=candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, i, sum);
        path.pop_back();
        sum-=candidates[i];
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    backtracking(candidates, target, 0, 0);
    return result;
    
}


int main(){
    vector<int> nums = {2,3,6,7};
    vector<vector<int>> result = combinationSum(nums, 7);
    for(auto res : result){
        cout<<'[';
        for(int i : res) cout<<i<<" ";
        cout<<']'<<endl;
    }
    return 0;
}