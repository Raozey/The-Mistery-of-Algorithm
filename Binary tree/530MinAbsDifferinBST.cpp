#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* pre = nullptr;
int result = INT_MAX;

void getMinimumDifference(TreeNode* cur){
    if(cur == nullptr) return;
    getMinimumDifference(cur->left);
    if(pre != nullptr) result = min(result, cur->val - pre->val);
    pre = cur;
    getMinimumDifference(cur->right);
}

void dfs(TreeNode* root, int& prevalue){
    if(root == nullptr) return;
    dfs(root->left, prevalue);
    if(prevalue == -1) prevalue = root->val;
    else{
        result = min(result, root->val - prevalue);
        prevalue = root->val; 
    }
    dfs(root->right, prevalue);


}

void getMinimumDifference2(TreeNode* root){
    int prevalue = -1;
    dfs(root, prevalue);
}

int main(){
    /**
     * 构造一棵二叉搜索树
     *     12
     *    / \
     *   8   30
     *  / \
     * 4   9
     *      \
     *       10
     */
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(10);


    // 递归方法1
    getMinimumDifference(root);

    // 递归方法2
    getMinimumDifference2(root);
    cout<<"Minimum Difference: "<<result<<endl;
    printTree(root);
    return 0;
}