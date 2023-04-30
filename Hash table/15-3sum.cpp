
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) return result;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        // 双指针
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            if(nums[i] + nums[left] + nums[right] == 0){
                result.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[right - 1] == nums[right]) right--;
                while(left < right && nums[left + 1] == nums[left]) left++;
                left++;
                right--;
            }
            else if(nums[i] + nums[left] + nums[right] > 0) right--;
            else left++;
        }
    }
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(nums);
    for(auto res: result) {
        for(int i : res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}