#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that 
no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. 
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/
vector<vector<string>> result;

bool isValid(vector<string>& chessBoard, int row, int col, int n){
    //只需要考虑row这一层上面的情况
    //在[row][col]这个位置放Q是否有效
    //不需要考虑row这一层下面的情况
    
    //列检查
    for(int i = 0; i < row; i++){
        if(chessBoard[i][col] == 'Q') return false;
    } 

    //当前点左上对角线检查
    for(int i = row - 1, j = col - 1; i>=0 && j >= 0; i--, j--){
        if(chessBoard[i][j] == 'Q') return false;
    }
    //当前点右上对角线检查
    for(int i = row - 1, j = col + 1; j < n && i >= 0; j++, i--){
        if(chessBoard[i][j] == 'Q') return false;
    }
    return true;
}

void backtracking(vector<string>& chessBoard, int n, int row){
    if(row == n) result.push_back(chessBoard);

    for(int col = 0 ; col < n; col++){
        if(isValid(chessBoard, row, col, n)){
            chessBoard[row][col] = 'Q';
            backtracking(chessBoard, n, row+1);
            chessBoard[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> chessBoard(n, string(n,'.'));
    backtracking(chessBoard, n, 0);
    return result;

}


int main(){
    vector<vector<string>>  res = solveNQueens(4);

    // when n = 4, there are two options
    // .Q..
    // ...Q
    // Q...
    // ..Q.

    // ..Q.
    // Q...
    // ...Q
    // .Q..

    for(auto i : res){
        for(string j : i){
            cout<<j<<endl;
        }
        cout<<"-----------"<<endl;
    }
    return 0;
}