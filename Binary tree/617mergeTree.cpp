#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

// TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
//     // 用root1作为返回值
//     if(root1 == nullptr) return root2;
//     if(root2 == nullptr) return root1;
//     root1->val += root2->val;
//     root1->left = mergeTrees(root1->left, root2->left);
//     root1->right = mergeTrees(root1->right, root2->right);
//     return root1;
// }

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
    // new新的节点作为作为返回值
    if(root1 == nullptr) return root2;
    if(root2 == nullptr) return root1;
    auto merged = new TreeNode(root1->val + root1->val);
    merged->left = mergeTrees(root1->left, root2->left);
    merged->right = mergeTrees(root1->right, root2->right);
    return merged;
}


int main(){
    /**
     * 构造一棵二叉树1
     *     1
     *    / \
     *   2   3
     *  / \
     * 4   5
     */
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    /**
     * 构造一棵二叉树2
     *     1
     *    / \
     *   2   3
     *  /     \
     * 4       5
     */
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);

    TreeNode* root = mergeTrees(root1, root2);

    // 输出翻转后的二叉树
    printTree(root);
    //     __2     
    //    /   \
    //   4     6
    //  / \     \
    // 8   5     5
    return 0;
}