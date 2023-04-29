#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//交换当前元素与之后最小元素的位置
void selectSort(vector<int>& nums){
    int minIndex;
    for(int i = 0; i < nums.size(); i++){
        minIndex = i;
        for(int j = i+1; j < nums.size(); j++){
            if(nums[j] < nums[i]) minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}


int main(){
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};

    selectSort(nums);

    for(int i : nums) cout<<i<<" ";
    cout<<endl;

    return 0;
}