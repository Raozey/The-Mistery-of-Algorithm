#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 首值快排
void quickSort(vector<int>& nums, int left, int right){
    if(left < right){
        int key = nums[left];
        int start = left;
        for(int j = left + 1; j < right; j++){
            if(nums[j] < key) swap(nums[j], nums[++start]);
        }
        nums[left] = nums[start];
        nums[start] = key;
        quickSort(nums, left, start - 1);
        quickSort(nums, start + 1, right);
    }
}


// 随机快排
void RquickSort(vector<int>& nums, int left, int right){
    if(left < right){
        // Trick:取随机的元素交换到首值
        int randIndex = rand()%(right - left) + left;
        swap(nums[left], nums[randIndex]);
        int key = nums[left];
        int start = left;
        for(int j = left + 1; j < right; j++){
            if(nums[j] < key) swap(nums[j], nums[++start]);
        }
        nums[left] = nums[start];
        nums[start] = key;
        quickSort(nums, left, start - 1);
        quickSort(nums, start + 1, right);
    }
}


int main(){
    vector<int> nums = {5,2,3,1,12,34,5,6,78,9,88};

    RquickSort(nums, 0, nums.size() - 1);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}