#include <iostream>
#include <algorithm>
#include <string>
#include "printTree.h"

using namespace std;
TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    int maxindex = 0;
    for(int i = 1; i < nums.size(); i++){
        if (nums[maxindex] < nums[i]){
            maxindex = i;
        }
    }
    TreeNode* root = new TreeNode(nums[maxindex]);
    vector<int> leftpart(nums.begin(), nums.begin() + maxindex);
    vector<int> rightpart(nums.begin() + maxindex +1, nums.end());
    if(leftpart.size() > 0) root->left = constructMaximumBinaryTree(leftpart);
    if(rightpart.size() > 0) root->right = constructMaximumBinaryTree(rightpart);
    return root;
}

int main(){
    /**
     * 从数组构造一棵二叉树
     * [3,2,1,6,0,5]
     *       6
     *    /    \
     *   3      5  
     *    \    /
     *     2  0  
     *      \
     *       1
     */
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    printTree(root);
    return 0;
}