#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(vector<int>& nums, int l, int r){
    if(l >= r) return;
    int mid = (l + r)/2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    vector<int> tmp(nums.size(), 0);
    int i = l;
    int j = mid + 1;
    int count = l;
    // 假定[l, mid] [mid+1, r]两个序列有序，进行合并
    // 先把结果存在tmp中再转移到nums
    while(i <= mid && j <= r){
        if(nums[i] < nums[j]){
            tmp[count++] = nums[i++];
        }
        else{
            tmp[count++] = nums[j++];
        }
    }
    if(i <= mid && j > r){
        while(i <= mid) tmp[count++] = nums[i++];
    }
    if(i > mid && j <= r){
        while(j <= r) tmp[count++] = nums[j++];
    }

    for(int m = l; m <=r; m++){
        nums[m] = tmp[m];
    }
}

int main(){
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};

    mergeSort(nums, 0, nums.size() - 1);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}