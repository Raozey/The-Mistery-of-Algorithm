#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* searchBST(TreeNode* root, int val){
    if(root == nullptr) return nullptr;
    if(root->val == val) return root;
    if(root->val > val) return searchBST(root->left, val);
    if(root->val < val) return searchBST(root->right, val);
    return nullptr;
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
 
    TreeNode* result = searchBST(root, 10);

    cout<<"search val:"<<( result == nullptr ? "no" : to_string(result->val))<<endl;
    printTree(root);

    return 0;
}