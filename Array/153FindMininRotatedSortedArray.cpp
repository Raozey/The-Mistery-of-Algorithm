#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> nums, int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left < right){
        int middle = (left +  right)/2;
        if(nums[middle] > nums[right]) left = middle + 1;
        else if(nums[middle] < nums[right]) right = middle;
    }
    return nums[left];
}



int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<"search result: "<<findMin(nums, target)<<endl;
}