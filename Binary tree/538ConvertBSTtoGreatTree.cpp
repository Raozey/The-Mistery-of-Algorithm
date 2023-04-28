#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

// int sum = 0;
// void traversal(TreeNode* root){
//     if(root == nullptr) return;
//     traversal(root->right);
//     sum += root->val;
//     root->val = sum;
//     traversal(root->left);
// }

// TreeNode* convertBST(TreeNode* root){
//     //反中序遍历-右中左
//     traversal(root);
//     return root;
//  }


int pre = 0; // 记录前一个节点的数值
void traversal(TreeNode* cur){
    if(cur == nullptr) return;
    traversal(cur->right);
    cur->val += pre;
    pre = cur->val;
    traversal(cur->left);
}

TreeNode* convertBST(TreeNode* root) {
    traversal(root);
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
 
    TreeNode* result = convertBST(root);
    printTree(result);
    return 0;
}