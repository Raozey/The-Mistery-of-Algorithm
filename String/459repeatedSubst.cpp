#include<iostream>
#include<string>

using namespace std;

bool repeatedSubstringPattern(string& s) {
    return (s+s).find(s,1) != s.size();

}


string deleteExtreSpace(string & s){
    int slow = 0, fast = 0;
    while(fast < s.size() && s[fast] == ' ') fast++;
    for(; fast < s.size();){
        if(fast > 0 && s[fast - 1] == ' ' && s[fast] == ' ') fast++;
        else s[slow++] = s[fast++]; 
    }
    while(s[slow-1] == ' ') slow--;
    return s.substr(0, slow);

}

int main(){

    string s = "   abca  bcab   cabc  ";
    s = deleteExtreSpace(s);
    cout<<s;
    cout<<"-";






    // string s = "abcabcabcabc";
    // bool res = repeatedSubstringPattern(s);
    // cout<<" result : "<<res<<endl;
    // return 0;
}