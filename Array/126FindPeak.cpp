#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> nums){
    // 二分法papo
    int left = 0, right = nums.size()-1;
    // 不能取等于，要在等于的时候退出，保证mid+1可以取值
    while(left < right){
        int mid = (left + right)/2;
        if(nums[mid] < nums[mid+1]) left = mid+1;
        else right = mid;
    }
    return left;
   
}
int findPeakElement(vector<int> nums){
    int left = 0, right = nums.size() - 1, ans = -1;

    auto get = [&](int index) ->pair<int,int>{
        if(index == -1 || index == nums.size()) return {0,0};
        return {1, nums[index]};
    };

    while(left <= right){
        int mid =(left + right)/2;
        if(get(mid) > get(mid + 1) && get(mid) > get(mid - 1)){
            ans = mid;
            break;
        }
        if(get(mid) < get(mid + 1)) left = mid + 1;
        else right = mid - 1;
    }
    return ans;

}

int main(){
    vector<int> nums = {1,2,1,3,5,6,4};

    cout<<"find Peak Element result: "<<findPeakElement(nums)<<endl;
}