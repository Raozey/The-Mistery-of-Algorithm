#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(root == nullptr){
        TreeNode* node = new TreeNode(val);
        root = node;
    }
    if(root->val < val) root->right = insertIntoBST(root->right, val);
    if(root->val > val) root->left = insertIntoBST(root->left, val);

    return root;
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
 
    TreeNode* result = insertIntoBST(root, 14);

    // cout<<"search val:"<<( result == nullptr ? "no" : to_string(result->val))<<endl;
    printTree(result);
    return 0;
}