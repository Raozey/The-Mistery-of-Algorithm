#include<iostream>
#include<vector>
using namespace std;


// Given an integer array nums, 
// return true if you can partition the array into two subsets such that the sum of the elements 
// in both subsets is equal or false otherwise.

bool canPartition(vector<int>& nums){
    int sum = 0;
    for(int i : nums) sum += i;
    if(sum % 2 == 1) return false;
    int target = sum / 2;

    //使用0-1背包
    //物品为nums中的元素，价值和重量相等
    //背包的最大容量为 target,当用背包装满后装到的价值为target则找到了符合条件的子集
    // 我们的目标就是要找到元素集合使得其和为target
    // 于是我们去装背包，装进去之后如果没装满，则说明符合条件的集合

    vector<int> dp(target + 1, 0);
    // 初始化
    dp[0] = 0;

    // 开始装包，先遍历物品再倒序遍历容量
    for(int i = 0; i < nums.size(); i++){
        for(int j = target; j >= nums[i]; j--){
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    if(dp[target] == target) return true;
    return false;
}

//使用二维dp数组
bool canPartition2(vector<int>& nums) {
    int sum = 0;
    for(int i : nums) sum += i;
    if(sum % 2 == 1) return false;
    int target = sum / 2;

    //用二维背包做
    vector<vector<int>> dp(nums.size(), vector<int>(target+1,0));

    // 初始化
    for(int i = 0; i < nums.size(); i++) dp[i][0] = 0;
    for(int j = nums[0]; j <= target; j++) dp[0][j] = nums[0];

    // // 先遍历物品再遍历容量
    // for(int i = 1; i < nums.size(); i++){
    //     for(int j = 1; j <= target; j++){
    //         if(j < nums[i]) dp[i][j] = dp[i-1][j];
    //         else dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
    //     }
    // }

    // 先遍历容量再遍历物品
    for(int j = 1; j <= target; j++){
        for(int i = 1; i<nums.size(); i++){
            if(j < nums[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
        }
    }
    
    if(dp[nums.size()-1][target] == target) return true;
    return false;
}


int main(){
    vector<int> nums = {1,5,11,5};
    bool res = canPartition(nums);
    cout<<"res: "<<res<<endl;
    return 0;
}