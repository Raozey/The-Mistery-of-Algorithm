#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 每一件物品其实只有两个状态，取或者不取
    
    vector<int> weigths = {1,3,4};
    vector<int> values = {15,20,20};
    int bagweight = 4;

    int items = weigths.size(); //item 从0开始计数，一共有items个物品

    // 一维dp数组
    // dp[j]:容量为j的背包，所背的物品价值可以最大为dp[j]
    vector<int> dp(bagweight + 1, 0);

    // 初始化dp数组
    // 当背包容量为0的时候，所能放的最大的价值也是0
    dp[0] = 0;

    // 物品i进来的时候，可以选择放或者不放
    // 放：价值为 dp[j - weight[i]] + value[i]
    // 不放：价值为dp[j]
    
    // 先遍历物品，再遍历背包容量，背包容量需要倒序遍历
    for(int i = 0; i < items; i++){
        for(int j = bagweight; j >= weigths[i]; j--){
            dp[j] = max(dp[j], dp[j - weigths[i]] + values[i]);
        }
    }

    int maxvalue = dp[bagweight];
    cout<<"maxvalue: "<<maxvalue<<endl;  //35, 放物品0和物品1


    return 0;
}