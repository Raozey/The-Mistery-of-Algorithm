#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void reverseString(string& s, int left, int right) {
    while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string reverseStr(string s, int k) {
    for(int i = 0; i < s.size(); i += 2*k){
        if(i + k > s.size()){
            reverseString(s, i, s.size() - 1);
        }
        else reverseString(s, i, i + k - 1);
    }
    return s;
}
//用库函数实现的要注意区间的边界
// string reverseStr(string s, int k) {
//     for(int i = 0; i < s.size(); i += 2*k){
//         if(i + k > s.size()){
//             reverse(s.begin() + i, s.end());
//         }
//         else reverse(s.begin() + i, s.begin() + i + k); //左闭右开区间
//     }
//     return s;
// }


int main(){
    string s = "abcdefg";
    s = reverseStr(s, 2);
    cout<<s<<endl;
    return 0;
}


