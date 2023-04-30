#include<iostream>
#include<string.h>
using namespace std;

bool isAnagram(string s, string t){
    int record[26] = {0}; //初始化全为0
    // int record[26] = {1}; //第一个值初始化为1，其余全为0
    // memset(record, -1, sizeof(int)*26);//初始化全为-1
    for (int i = 0; i < 26; i++) cout<<record[i]<<" ";

    

    for(char i : s) record[i - 'a']++;
    for(char i : t) record[i - 'a']--;
    for(int i = 0; i < 26; i++){
        if(record[i] != 0 ) return false;
    }
    return true;

}

int main(){
    string s = "anagram";
    string t = "nagaram";

    bool res = isAnagram(s,t);
    cout<<"is Anagram : "<<res<<endl;
    return 0;
}