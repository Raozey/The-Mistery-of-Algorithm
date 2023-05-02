#include <iostream>
#include <vector>
using namespace std;




int uniquePaths(int m, int n) {
    //二维dp数组
    //dp[i][j]表示从零点开始,到(i,j)位置有多少种方法
    //dp的横向和纵向下标为0的维度都没有使用
    //从下标为1开始，到下标为n或者m结束，正好n或者m个格子。
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i <= m; i++){
        dp[i][1] = 1;
    }

    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main(){
    int res = uniquePaths(3, 2);
    cout<<"Res: "<<res<<endl;

    // Total 3 ways:
    // 1. Right -> Down -> Down
    // 2. Down -> Down -> Right
    // 3. Down -> Right -> Down
    return 0;


}