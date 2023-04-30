#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

    

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int res = 0;    
    unordered_map<int,int> map12;
    for(int a : nums1){
        for(int b : nums2) map12[a+b]++;
    }
    for(int c : nums3){
        for(int d : nums4){
            if(map12.find(0-c-d) != map12.end()) res += map12[0-c-d];
        }
    }
    return res;
}


int main(){

    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};

    int res = fourSumCount(nums1, nums2, nums3, nums4);
    cout<<"result: "<<res;
    return 0;

}