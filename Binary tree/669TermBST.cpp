#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* trimBST(TreeNode* root, int low, int high){
    if(root == nullptr) return nullptr;
    if(root->val > high) return trimBST(root->left, low, high);
    else if(root->val < low) return trimBST(root->right, low, high);
    else{
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
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
 
    TreeNode* result = trimBST(root, 9, 30);
    printTree(result);
    return 0;
}