#include<iostream>
#include<vector>
#include<string>

using namespace std;

const string smap[10] = {
    "", //0
    "", //1
    "abc", //2
    "def", //3
    "ghi", //4
    "jkl", //5
    "mno", //6
    "pqrs", //7
    "tuv", //8
    "wxyz", //9
};

vector<string> result;
string path;
void backtracking(string digits, int startindex){
    if(path.size() == digits.size()){
        result.push_back(path);
        return;
    }
    // 双重for回溯，没太有意义，稀里糊涂对了
    // 严格分析一下，当循环体内 i=0，只运行这一次足够了，后面的纯属多余
    // 因为后面的运行多少次都不可能达到条件，即永远少1-n位数数字。
    for(int i = startindex; i < digits.size(); i++){
        string contain = smap[digits[i] - '0'];
        for(int j = 0; j < contain.size(); j++){
            path.push_back(contain[j]);
            backtracking(digits, i+1);
            path.pop_back();
        }
    }
}

void backtracking2(const string& digits, int index){
    if (index == digits.size()){
        result.push_back(path);
        return; //一定要return，不然最后一次index = digits.size()会导致越界
    }

    int digit = digits[index] - '0'; //对应的数字
    string letters = smap[digit];
    for(int i = 0; i < letters.size(); i++){
        path.push_back(letters[i]);
        backtracking2(digits, index+1);
        path.pop_back();
    }
}



vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return result;
    }
    backtracking2(digits, 0);
    return result;
}

int main(){
    string digits = "23";
    vector<string>  result = letterCombinations(digits);
    for(string res : result) cout<<res<<endl;
    return 0;
}