#include <iostream>
#include <vector>
using namespace std;





void test_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    // 先遍历物品，在遍历背包->在求组合时候使用
    for(int i = 0; i < weight.size(); i++){
        for(int j = weight[i]; j <= bagWeight; j++){
            dp[j] = max(dp[j], dp[j- weight[i]] + value[i]);
        }
    }
    // 先遍历背包，在遍历物品->在求排列时候使用
    for(int j = 0 ; j <= bagWeight; j++){
        for(int i = 0; i<weight.size(); i++){
            if(j >= weight[i]) dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    
    
   
    cout << dp[bagWeight] << endl;
}
int main() {
    test_CompletePack();
}
