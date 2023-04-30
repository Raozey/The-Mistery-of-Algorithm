#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    // unordered_set<int> set1;
    // unordered_set<int> set2;
    // vector<int> ans;
    // for(int i : nums1) set1.insert(i);
    // for(int i : nums2) set2.insert(i);
    // for(int i : set1){
    //     if(set2.find(i) != set2.end()) ans.push_back(i);
    // }
    // return ans;
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> resset;
    for(int i : nums2){
        if(set1.find(i) != set1.end()) resset.insert(i);
    }
    return vector<int>(resset.begin(), resset.end());
}

int main(){
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    vector<int> res = intersection(nums1, nums2);
    for(int i : res) cout<<i<<" "<<endl;
    return 0;
}