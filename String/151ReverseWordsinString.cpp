#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string deleteExtreSpace(string & s){
    int slow = 0, fast = 0;
    // 删除头部空格
    while(fast < s.size() && s[fast] == ' ') fast++;
    // 删除中间空格
    for(; fast < s.size();){
        if(fast > 0 && s[fast - 1] == ' ' && s[fast] == ' ') fast++;
        else s[slow++] = s[fast++]; 
    }
    // 删除尾部空格,只可能有一个,在上面赋值了这个尾部空格后++了,所以是slow-1
    if(s[slow-1] == ' ') slow--;
    // .substr(i,m) 从下标i 开始的 m个元素
    return s.substr(0, slow);  //左闭右开区间

}
// 删除空格版本二
void removeExtraSpaces(string& s) {
    int slow = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] != ' '){
            if(slow != 0) s[slow++] = ' ';
            while(i<s.size() && s[i] != ' ') s[slow++] = s[i++];
        }
    }
    s.resize(slow);
}






string reverseWords(string s) {
    s = deleteExtreSpace(s);
    reverse(s.begin(), s.end());
    int start = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') {
            reverse(s.begin() + start, s.begin()+ i);
            start = i+1;
        }
    }
    reverse(s.begin() + start, s.end());
    return s;
}



int main(){
    string  s = "the sky is blue";
    // string  s = "  hello world  ";
    // string  s = " a good   example";
    s = reverseWords(s);
    cout<<s<<endl;
    return 0;
}