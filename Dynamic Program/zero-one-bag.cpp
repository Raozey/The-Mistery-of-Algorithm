#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> weigths = {1,3,4};
    vector<int> values = {15,20,20};
    int bagweight = 4;

    int items = weigths.size(); //item 从0开始计数，一共有items个物品

    // 二维dp数组
    // dp[i][j]:从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
    vector<vector<int>> dp(items, vector<int>(bagweight + 1, 0));

    // 初始化dp数组
    // 当背包容量为0的时候，从任意数量的物品中选取都是0
    for(int i = 0; i < items; i++) dp[i][0] = 0;

    // 选择物品0放与不放则会产生两个阶段
    // 当物品0的重量小于当前的背包容量j的时候，可以把物品0放进去，dp[0][j] = values[0]
    // 当物品0的重量大于当前的背包容量j的时候，不可以把物品0 放进去，dp[0][j] = 0;
    for(int j = weigths[0]; j <= bagweight; j++) dp[0][j] = values[0];


    //初始化了第一排和第一列
    // 接下来使用状态转移方程来遍历更新其他值

    // 背包容量为j的时候， 新进来一个物品i，有两种情况
    // 放物品i: dp[i][j] = dp[i-1][j]
    // 不放物品i: dp[i][j] = dp[i-1][j-weights[i]] + values[i]
    // 所以状态转移方程为 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);

    //在固定容量j的时候，遍历物品i 
    for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
        for(int i = 1; i < items; i++) { // 遍历物品
            if (j < weigths[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigths[i]] + values[i]);
        }
    }

   //在确定物品i的时候，遍历容量
    // for(int i = 1; i < items; i++) { // 遍历物品
    //     for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
    //         if (j < weigths[i]) dp[i][j] = dp[i - 1][j];
    //         else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weigths[i]] + values[i]);
    //     }
    // }


    int maxvalue = dp[items-1][bagweight];
    cout<<"maxvalue: "<<maxvalue<<endl;  //35, 放物品0和物品1


    return 0;
}