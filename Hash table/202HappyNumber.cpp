#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


int getsum(int n){
    int sum = 0;
    while(n){
        sum += (n%10)*(n%10);
        n = n/10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> res;
    while(n!=1){
        n = getsum(n);
        if(res.find(n) != res.end()) return false;
        res.insert(n);
    }
    return true;
}


int main(){


    bool res = isHappy(19);
    cout<<"number : "<<19<<" is happy number: "<<res<<endl;

    res = isHappy(2);
    cout<<"number : "<<2<<" is happy number: "<<res<<endl;
    return 0;
}