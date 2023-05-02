#include<iostream>
#include<vector>
using namespace std;





int lastStoneWeightII(vector<int>& stones) {
    // 尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小，化解成01背包问题
    int sum = 0 ;
    for(int i : stones) sum += i;
    int target = sum/2;
    vector<int> dp(target+1, 0);
    for(int i = 0; i<stones.size(); i++){
        for(int j = target; j>= stones[i]; j--){
            dp[j]= max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return (sum - dp[target]) - dp[target];
}

int main(){
    vector<int> nums = {31,26,33,21,40};
    int res = lastStoneWeightII(nums);
    cout<<"res: "<<res; //5
    // {2,7,4,1,8,1} -> 1
    return 0; 
}