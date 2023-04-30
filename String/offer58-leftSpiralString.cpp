#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.end() - n);
    reverse(s.end() - n, s.end());
    return s;
}



int main(){
    string s = "abcdefg";
    s = reverseLeftWords(s, 2);
    cout<<s<<endl;
    return 0;
}


