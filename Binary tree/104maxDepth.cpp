#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "printTree.h"

using namespace std;

int maxDepth(TreeNode* root){
    // 递归求最大深度
    if(root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int depth = 0;
void reversalMaxDepth(TreeNode* root, int index){
    depth = index > depth ? index : depth;
    // 剪枝操作，可以不要
    // 当前节点为叶子节点，直接返回，不需要走后面的两步判断
    // if(root->left == nullptr && root->right == nullptr) return;

    if(root->left != nullptr){
        index++;
        reversalMaxDepth(root->left, index);
        index--;
    }
    if(root->right != nullptr){
        index++;
        reversalMaxDepth(root->right, index);
        index--;
    }
}


int main(){
    /**
     * 构造一棵二叉树
     *     1
     *    / \
     *   2   3
     *  / \
     * 4   5
     *      \
     *       5
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(5);
    // 递归法
    // depth = maxDepth(root);

    // 回溯法
    if (root == nullptr) return depth;
    reversalMaxDepth(root, 1);

    cout<<"MAX depth:"<<depth<<endl;
    printTree(root);

    return 0;
}
