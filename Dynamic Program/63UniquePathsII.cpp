#include <iostream>
#include <vector>
using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if(m == 0) return 0;
    int n = obstacleGrid[0].size();
    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
    vector<vector<int>> dp(m, vector<int>(n,0));
    
    // 初始化二维边界
    for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
    for(int i = 0; i < n && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0; //有障碍则这个地方的值为0
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int res = uniquePathsWithObstacles(obstacleGrid);
    cout<<"Res: "<<res<<endl;

    // there are two ways to get there
    // 1. Right -> Right -> Down -> Down
    // 2. Down -> Down -> Right -> Right
    return 0;
}