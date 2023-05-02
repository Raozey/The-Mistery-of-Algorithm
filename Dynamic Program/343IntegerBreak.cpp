#include <iostream>
#include <vector>
using namespace std;


int integerBreak(int n) {
    // dp[i]拆分数字i所能得到的最大的值
    vector<int> dp(n+1, 0);
    dp[2] = 1;
    // 两种方法得到dp[i]，将j从1遍历到i-1,
    // 情况一：拆分为两个数字j 和 i-j
    // 情况二：拆分为多个数组j 和 集合M（和为i-j）, 此时的和为j*dp[i-j]
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= i/2; j++){
            dp[i] = max(dp[i], max((j*dp[i-j]), j*(i-j)));
        }
    }
    return dp[n];
}

int main(){
    int n = 10;
    int res = integerBreak(n);
    cout<<res<<endl; //36: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
}