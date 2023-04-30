#include <iostream>
#include <vector>
using namespace std;

bool search2d(vector<vector<int>> matrix, int target){
    int m = matrix.size(); if(m == 0) return false;
    int n = matrix[0].size(); if(n==0) return false;
    int i = 0, j = n-1;
    while(i < m-1 && j >= 0){
        if(matrix[i][j] == target ) return true;
        else if(matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}



int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout<<"search result: "<<((search2d(matrix, target) == true) ? "yes" : "no")<<endl;

}