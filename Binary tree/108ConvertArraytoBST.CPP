#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.size() == 0) return nullptr;
    int left = 0;
    int right = nums.size() -1;
    int mid = (left + right)/2;
    TreeNode* root = new TreeNode(nums[mid]);

    vector<int> numsleft(nums.begin(), nums.begin() + mid);
    vector<int> numsright(nums.begin() + mid + 1, nums.end());

    root->left = sortedArrayToBST(numsleft);
    root->right = sortedArrayToBST(numsright);

    return root;

}

int main(){
    /**
     * 从有序数组构造一棵二叉搜索树、
     * [-10,-3,0,5,9]
     *        0 
     *       /  \
     *    -10     5
     *      \      \
     *      -3      9
     *  
     */
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* result = sortedArrayToBST(nums);
    printTree(result);
    return 0;
}