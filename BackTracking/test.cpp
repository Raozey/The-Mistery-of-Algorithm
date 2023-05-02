#include<iostream>
#include<string>
using namespace std;

int main(){
    string s = "255255255";

    string path;

    path += s.substr(0,3);
    path += s.substr(3,3);
    cout<<path<<endl;
    path.erase(path.end() - 3, path.end());
    cout<<path.size()<<endl;



    return 0;
}