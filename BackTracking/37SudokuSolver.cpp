#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

bool isValid(int row, int col, char val, vector<vector<char>>& board){
    // 判断行里是否重复    
    for (int i = 0; i < 9; i++) { 
        if (board[row][i] == val) {
            return false;
        }
    } 
    // 判断列里是否重复
    for (int j = 0; j < 9; j++) { 
        if (board[j][col] == val) {
            return false;
        }
    } 
    // 判断9方格里是否重复
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;    
    for (int i = startRow; i < startRow + 3; i++) { 
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}



bool backtracking(vector<vector<char>>& board){
    for (int i = 0; i < board.size(); i++){          // 遍历行
        for (int j = 0; j < board[0].size(); j++){   // 遍历列
            if (board[i][j] == '.') {
                for (char k = '1'; k <= '9'; k++){   //(i, j) 这个位置放k是否合适
                        if (isValid(i, j, k, board)){
                        board[i][j] = k;                // 放置k
                        if (backtracking(board)) return true; // 找到合适一组立刻返回
                        board[i][j] = '.';              // 回溯，撤销k
                        }
                }
                return false;  // 9个数都试完了，都不行，那么就返回false 
            }
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
} 

void solveSudoku(vector<vector<char>>& board) {
    backtracking(board);
}


int main(){
    vector<vector<char>>  board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);


    for(auto line : board){
        for(char c : line){
            cout<<c<<" ";
        }
        cout<<endl;
    }

    return 0;
}