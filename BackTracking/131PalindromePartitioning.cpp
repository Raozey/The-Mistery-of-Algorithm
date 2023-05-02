#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.


vector<vector<string>> result;
vector<string> path;

bool isPalindrome(string s, int start, int end){
    while(start<end){
        if(s[start] != s[end]) return false;
        start++; end--;
    }
    return true;
}

void backtracking(string s, int startindex){
    if(startindex >= s.size()){
        result.push_back(path);
        return;
    }
    for(int i = startindex; i < s.size(); i++){
        if(isPalindrome(s, startindex, i)){
            path.push_back(s.substr(startindex, i - startindex + 1));
        }
        else continue;
        backtracking(s, i+1);
        path.pop_back();
    }

}

vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return result;
}



int main(){
    string s = "aab";
    result = partition(s);

    for(auto res : result) {
        for (string s : res)  cout<<s<<" ";
        cout<<endl;
    }

    
    return 0;
}