#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if(n <= 1) return 0;
    //dp[i]的含义: 爬到下标为i的台阶所需要的最少花费
    //楼梯的顶部不是cost的最后一个,而是cost的后一个
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;
    int res = 0; 
    for(int i = 2; i<=n; i++){
        int cost1 = cost[i-1] + dp[i-1];
        int cost2 = cost[i-2] + dp[i-2];
        dp[i] = min(cost1, cost2);
    }
    return dp[n];
}


int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    int res = minCostClimbingStairs(cost);
    cout<<res<<endl;
}