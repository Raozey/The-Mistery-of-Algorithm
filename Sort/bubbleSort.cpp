#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& nums){
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = 0 ; j < nums.size() - 1 - i; j++){
            if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }
}




void bubbleSortCut(vector<int>& nums){
    for(int i = 0; i < nums.size() - 1; i++){
        //每一轮都会把最大值放到最后面
        //若当前轮次没有发生交换，则当前子序列有序，直接退出
        bool flag = false;
        for(int j = 0; j < nums.size() - 1 - i; j++){
            if(nums[j] > nums[j+1]) {
                swap(nums[j+1], nums[j]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}

int main(){
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};

    bubbleSort(nums);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}