#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int test_ZERO_ONE_bag_two_dim(vector<int> weights, vector<int> values, int bagweight){
    // dp[i][j] 表示从下标为[0-i]的物品里任意取，
    // 放进容量为j的背包，价值总和最大是多少。
    vector<vector<int>> dp(weights.size(), vector<int>(bagweight + 1, 0));
    //初始化背包容量为0时最多能装的物品价值
    for(int i = 0; i < weights.size(); i++) dp[i][0] = 0;
    //初始化放物品0时各个重量的背包容量最多能装的物品价值
    for(int j = 0; j <= bagweight; j++){
        if(j >= weights[0]) dp[0][j] = values[0];
    }
    //先遍历物品，再遍历背包
    for(int i = 1; i < weights.size(); i++){
        for(int j = 0; j <= bagweight; j++){
            // 不放物品i：由dp[i - 1][j]推出
            // 放物品i：由dp[i - 1][j - weight[i]]推出
            if(j < weights[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j - weights[i]] + values[i], dp[i - 1][j]);
        }
    }
    return dp[weights.size() - 1][bagweight];
}

int test_ZERO_ONE_bag_one_dim(vector<int> weights, vector<int> values, int bagweight){
    vector<int> dp(bagweight + 1, 0);
    //先遍历物品再遍历背包容量
    //正序遍历则开源重复添加某个物品
    
    for(int i = 0; i < weights.size(); i++){
        for(int j = bagweight; j >= weights[i]; j--){
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    //也可以先遍历背包再遍历物品
    // for(int j = 0; j <= bagweight; j++){
    //     for(int i = 0; i < weights.size(); i++){
    //         if(j >= weights[i]) dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    //     }
    // }
    return dp[bagweight];
}


int test_FULL_bag_one_dim(vector<int> weights, vector<int> values, int bagweight){
    vector<int> dp(bagweight + 1, 0);
    for(int i = 0; i < weights.size(); i++){
        for(int j = weights[i]; j <= bagweight; j++){
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[bagweight];
}



int main(){
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int bagweight = 4;
    int res = test_ZERO_ONE_bag_two_dim(weights, values, bagweight);
    int res2 = test_ZERO_ONE_bag_one_dim(weights, values, bagweight);
    int res3 = test_FULL_bag_one_dim(weights, values, bagweight);
    cout<<res3<<endl;
    return 0;
}
