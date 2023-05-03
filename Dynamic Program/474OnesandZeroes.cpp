#include<iostream>
#include<vector>
using namespace std;




int findMaxForm(vector<string>& strs, int m, int n) {
    // 01背包问题，双重重量
    // dp[i][j]:容量0（0的数目）为i, 容量1（1的数目）为j的背包最大的价值
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
    dp[0][0] = 0;

    for(string str : strs){//遍历物品
        int onenums = 0, zeronums = 0; //物品的两个重量
        for(char c : str) {
            if(c == '0') zeronums++;
            if(c == '1') onenums++;
        }
        //开始遍历背包
        for(int j = m; j >= zeronums; j--){
            for(int i = n; i >= onenums; i--){
                dp[j][i] = max(dp[j][i], dp[j-zeronums][i - onenums] + 1);
            }
        }

    }
    return dp[m][n];
}


int main(){
    vector<string> strs =  {"10","0001","111001","1","0"};
    int m = 5;
    int n = 3;
    int res = findMaxForm(strs, m, n);
    cout<<res<<endl; //4

    return 0;
}