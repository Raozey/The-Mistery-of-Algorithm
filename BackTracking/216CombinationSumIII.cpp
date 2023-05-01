#include<iostream>
#include<vector>
using namespace std;

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
vector<vector<int>> result;
vector<int> path;

void backtracking(int k, int n, int index, int sum){
    //剪枝操作，若和超过了目标，直接返回
    if(sum > n) return;
    if(path.size() == k){
        if(sum == n) result.push_back(path);
        return; //剪纸操作，若数目符合，但是大小不符合直接返回
    }

    for(int i = index; i <= 9 - (k - path.size()) + 1; i++){
        sum += i;
        path.push_back(i);
        backtracking(k, n, i+1, sum);
        path.pop_back();
        sum -= i;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1, 0);
    return result;
}

int main(){
    vector<vector<int>> result = combinationSum3(3, 9);

    for(auto res : result){
        cout<<'[';
        for(int i : res) cout<<i<<" ";
        cout<<']'<<endl;
    }
    return 0;
}