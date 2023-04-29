#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Maxheapify(vector<int>& nums, int i, int len){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int larger = i;
    if(left <= len && nums[left] > nums[larger]) larger = left;
    if(right <= len && nums[right] > nums[larger]) larger = right;
    if(larger != i) {
        swap(nums[i], nums[larger]);
        Maxheapify(nums, larger, len);
    }

}

void bulidHeap(vector<int>& nums, int len){
    // 从最后一个非叶子节点开始维护
    for(int i = len/2; i >= 0; i--){
        Maxheapify(nums, i ,len);
    }
}


void heapSort(vector<int>& nums){
    int len = nums.size() -1;
    bulidHeap(nums, len);
    for(int i = len; i >= 1; i--){
        swap(nums[0], nums[i]);
        len--; 
        Maxheapify(nums, 0, len);
    }
}

int main(){
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};

    heapSort(nums);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}