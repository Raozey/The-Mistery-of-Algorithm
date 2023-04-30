#include<string>
#include<iostream>
using namespace std;



string replaceSpace(string s) {
    int count = 0;
    for(char c : s) if(c == ' ') count++;
    int oldsize = s.size();
    int newsize = oldsize + count*2;
    s.resize(newsize);
    
    int newindex = newsize - 1;
    for(int oldindex = oldsize-1; oldindex >= 0; ){
        if(s[oldindex] == ' '){
            s[newindex--] = '0';
            s[newindex--] = '2';
            s[newindex--] = '%';
            oldindex--;
        }
        else{
            s[newindex--] = s[oldindex--];
        }
    }
    return s;
}

int main(){
    string s = "We are happy.";
    s = replaceSpace(s);
    cout<<s<<endl;
    return 0;
}