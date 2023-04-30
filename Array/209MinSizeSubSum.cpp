#include <iostream>
#include <vector>
using namespace std;


int minSubArrayLen(vector<int>& nums, int target){
    int result = INT16_MAX;
    int start = 0;
    int sum = 0;
    for(int end = 0; end < nums.size(); end++){
        sum += nums[end];
        while(sum >= target){
            result = min(result, end - start + 1);
            sum -= nums[start++];
        }
    }
    return result == INT_MAX ? 0 : result;
       
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int result = minSubArrayLen(nums, 7);

    cout<<" result: "<<result<<endl;
    
    return 0;
}