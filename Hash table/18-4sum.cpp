
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 本题在leetcode中需要用long存储四个和的结果


vector<vector<int>> fourSum(vector<int>& nums, int target)  {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int k = 0; k < nums.size(); k++){

        if(nums[k] > target && nums[k] >= 0) break;
        if(k > 0 && nums[k] == nums[k-1]) continue;

        for(int i = k+1; i < nums.size(); i++){

            if(nums[k]  + nums[i] > target && nums[i] >= 0) break;
            if(i > k+1 && nums[i] == nums[i-1]) continue;

            // 双指针
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[k] + nums[i] + nums[left] + nums[right] == target){
                    result.push_back({nums[k], nums[i], nums[left], nums[right]});
                    while(left < right && nums[right - 1] == nums[right]) right--;
                    while(left < right && nums[left + 1] == nums[left]) left++;
                    left++;
                    right--;
                }
                else if(nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                else left++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> result = fourSum(nums, 0);
    for(auto res: result) {
        for(int i : res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}