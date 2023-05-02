#include <iostream>
#include <vector>
using namespace std;


int numTrees(int n) {
    // dp[i]表示1到i为节点组成的二叉搜索树的个数为dp[i]
    // 遍历j的取值范围[1, i]
    // dp[i] += dp[j - 1] * dp[i - j]
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

int main(){
    int n = 3;
    int res = numTrees(n);
    cout<<res<<endl; //5
}

// switch(n){
//     case 1: return 1;
//     case 2: return 2;
//     case 3: return 5;
//     case 4: return 14;
//     case 5: return 42;
//     case 6: return 132;
//     case 7: return 429;
//     case 8: return 1430;
//     case 9: return 4862;
//     case 10: return 16796;
//     case 11: return 58786;
//     case 12: return 208012;
//     case 13: return 742900;
//     case 14: return 2674440;
//     case 15: return 9694845;
//     case 16: return 35357670;
//     case 17: return 129644790;
//     case 18: return 477638700;
//     case 19: return 1767263190;
//     default: return 0;  
// };