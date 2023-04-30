#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

    

vector<int> twoSum(vector<int>& nums, int target) {
    // 用set返回数字
    // unordered_set<int> uset;
    // for(int i = 0; i < nums.size(); i++){
    //     if(uset.find(target - nums[i]) != uset.end()){
    //         return {nums[i], target - nums[i]};
    //     }
    //     else uset.insert(nums[i]);
    // }
    // return {INT_MAX, INT_MAX};

    // 用map记录下标
    unordered_map<int, int> umap;  //first: value, second: index
    for(int i = 0; i < nums.size(); i++){
        if(umap.find(target - nums[i]) != umap.end()){
            return{i, umap[target - nums[i]]};
        }
        // else umap.insert(pair<int,int>(nums[i], i));
        else umap.insert(make_pair(nums[i], i));
    }
    return {INT_MAX, INT_MAX};
}


int main(){

    vector<int> nums ={2,7,11,15};
    vector<int> res = twoSum(nums, 26);
    for(int i : res) cout<<i<<" ";
    return 0;

}