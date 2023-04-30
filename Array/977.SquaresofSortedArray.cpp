#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums){
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++; end--;
    }
}

vector<int> sortedSquares(vector<int>& nums){
        vector<int> ans;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            if(nums[left]*nums[left] > nums[right]* nums[right]) {
                ans.push_back(nums[left]*nums[left]);
                left++;
            }
            else{
                ans.push_back(nums[right]* nums[right]);
                right--;
            }
        }
        reverse(ans);
        // or use the algorithm
        // reverse(ans.begin(), ans.end());
        return ans;
}

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result = sortedSquares(nums);

    cout<<" result: "<<endl;
    
    for(int i = 0; i < result.size(); i++)  cout<<result[i]<<" ";
    return 0;
}