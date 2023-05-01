#include<iostream>
#include<vector>
using namespace std;

// Given two integers n and k, 
// return all possible combinations of k numbers chosen from the range [1, n].
vector<vector<int>> result;
vector<int> path;

void bactracking(int n, int k, int startIndex){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    for(int i = startIndex; i <= n; i++){
        path.push_back(i);
        bactracking(n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    bactracking(n, k, 1);
    return result;
}



int main(){
    vector<vector<int>> result = combine(4, 2);
    for(auto res : result){
        cout<<'[';
        for(int i : res) cout<<i<<" ";
        cout<<']'<<endl;
    }
    return 0;
}