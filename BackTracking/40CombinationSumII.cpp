#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

vector<vector<int>> result;  // 存放结果集合
vector<int> path;            // 符合符合条件的组合

void backtracking(vector<int>& candidates, int target, int index, int sum, vector<int>& used){
    if(sum > target) return;
    if(sum == target){
        result.push_back(path);
        return;
    }
    for(int i = index; i < candidates.size(); i++){
        if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == 0) continue;
        sum += candidates[i];
        path.push_back(candidates[i]);
        used[i] = 1;
        backtracking(candidates, target, i+1, sum, used);
        used[i] = 0;
        path.pop_back();
        sum -= candidates[i];
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> used(candidates.size(), 0);
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
}


int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    vector<vector<int>> result = combinationSum(nums, 8);
    for(auto res : result){
        cout<<'[';
        for(int i : res) cout<<i<<" ";
        cout<<']'<<endl;
    }

    return 0;
}