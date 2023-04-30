#include <iostream>
#include <vector>
using namespace std;

 vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
    int loop = n / 2; // 每个圈循环几次，例如n为奇数,矩阵中间的值需要单独处理
    int mid = n / 2;
    int count = 1; 
    int offset = 1; 
    int i,j;
    while (loop --){
        i = startx;
        j = starty;
        // 模拟填充上行从左到右(左闭右开)
        for (j = starty; j < n - offset; j++) {
            res[startx][j] = count++;
        }
        // 模拟填充右列从上到下(左闭右开)
        for (i = startx; i < n - offset; i++) {
            res[i][j] = count++;
        }
        // 模拟填充下行从右到左(左闭右开)
        for (; j > starty; j--) {
            res[i][j] = count++;
        }
        // 模拟填充左列从下到上(左闭右开)
        for (; i > startx; i--) {
            res[i][j] = count++;
        }
        startx++;
        starty++;
        offset++;
    }
    if (n % 2)  res[mid][mid] = count;
    return res;
 }


int main(){
    int n = 5;
    vector<vector<int>> res = generateMatrix(n);
    for(auto i : res) {
        for(int m : i) cout<<m<<" ";
        cout<<endl;
    }
    
}