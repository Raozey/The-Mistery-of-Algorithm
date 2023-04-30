#include <iostream>
#include <vector>
using namespace std;


int removeElement(vector<int>& nums, int val){
    int slow = 0, fast = 0;
    while(fast < nums.size()){
        if(nums[fast] == val) fast++;
        else{
            nums[slow] = nums[fast];
            slow++; fast++;
        }
    }
    return slow;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int result = removeElement(nums, 2);
    cout<<"remove Element result: "<<result<<endl;
    
    for(int i = 0; i < result; i++)  cout<<nums[i]<<" ";


    return 0;
}