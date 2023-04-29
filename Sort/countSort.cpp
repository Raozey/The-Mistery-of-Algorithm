#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& nums){
    int minNum = INT_MAX;
    int maxNum = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > maxNum) maxNum = nums[i];
        if(nums[i] < minNum) minNum = nums[i];
    }
    vector<int> counts(maxNum - minNum + 1, 0);
    for(int i : nums) counts[i - minNum]++;
    int index = 0;
    for(int i; i < counts.size(); i++){
        while(counts[i] != 0){
            nums[index++] = i + minNum;
            counts[i]--;
        }
    }
   
}

int main(){
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};

    countSort(nums);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}