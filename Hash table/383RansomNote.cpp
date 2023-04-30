#include<iostream>
#include<string.h>
using namespace std;
    
    
bool canConstruct(string ransomNote, string magazine) {
    if(magazine.size() < ransomNote.size()) return false;
    int record[26] = {0};
    for(char c : magazine){
        record[c - 'a']++;
    }
    for(char c : ransomNote){
        record[c - 'a']--;
        if(record[c - 'a'] < 0) return false;
    }
    return true;
}

int main(){
    string ransomNote = "aa";
    string magazine = "aab";
    bool res = canConstruct(ransomNote, magazine);
    cout<<"result is : "<<res;
    return 0;
}