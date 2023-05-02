#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> result;
vector<string> path;
// 使用string path进行回溯的时候边界出错，尚未找到问题


bool isValid(string s, int start, int end){
    if(start > end) return false;
    if(s[start] == '0' && start != end) return false;
    int num = 0;
    for(int i = start; i <= end; i++){
        if(s[i] < '0' || s[i] > '9') return false;
        num = num*10 + (s[i] - '0');
        if(num > 255)  return false;
    }
    return true;
}

string convert(vector<string> path){
    string res;
    for(string s : path) res += s;
    return res;
}

void backtracking2(string s, int startindex, int count){
    if(count == 3){
        if(isValid(s, startindex, s.size() - 1)) {
            string sone = convert(path);
            sone += s.substr(startindex, s.size() - 1 - startindex + 1);
            result.push_back(sone); 
        }
        return;
    }
    for(int i = startindex; i < s.size(); i++){
        if(isValid(s, startindex, i)){
            path.push_back(s.substr(startindex, i - startindex + 1));
            count++;
            path.push_back(".");

            backtracking2(s, i+1, count);

            path.pop_back();
            count--;
            path.pop_back();
        }else continue;
    }
}

// 直接在s上进行插入删除
void backtracking(string& s, int startIndex, int pointNum){
    if (pointNum == 3){
        if (isValid(s, startIndex, s.size() - 1)) {
            result.push_back(s);
        }
        return;
    }
    for (int i = startIndex; i < s.size(); i++){
        if (isValid(s, startIndex, i)){
            s.insert(s.begin() + i + 1 , '.'); // 在i的后面插入一个逗点
            pointNum++;
            backtracking(s, i + 2, pointNum);
            pointNum--;
            s.erase(s.begin() + i + 1);
        }
        else break; // 不合法，直接结束本层循环
    }
}


vector<string> restoreIpAddresses(string s) {
    backtracking(s, 0, 0);
    return result;
}



int main(){
    string digits = "25525511135";
    vector<string> result = restoreIpAddresses(digits);
    for(string res : result) cout<<res<<endl;
    return 0;
}