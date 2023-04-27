#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "printTree.h"

using namespace std;

bool compare(TreeNode* left, TreeNode* right){
    if(left == nullptr && right == nullptr) return true;
    if(left != nullptr && right == nullptr) return false;
    if(left == nullptr && right != nullptr) return false;
    if(left->val != right->val) return false;
    //当前节点对称，继续往下寻找，分为两侧
    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    return inside && outside;
}



bool isSymmetric(TreeNode* root) {
    // 递归判断是否为堆成
    // if(root == nullptr) return true;
    // return compare(root->left, root->right);

    // 使用队列层序遍历
    if(root == nullptr) return true;
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while(!que.empty()){
        TreeNode* leftNode = que.front(); que.pop();
        TreeNode* rightNode = que.front(); que.pop();
        if(leftNode == nullptr && rightNode == nullptr) continue;

        if( !leftNode || !rightNode || (leftNode->val != rightNode->val)){
            return false;
        }
        que.push(leftNode->left);
        que.push(rightNode->right);
        que.push(leftNode->right);
        que.push(rightNode->left);
    }
    return true;
}

int main(){
    /**
     * 构造一棵二叉树
     *     1
     *    /  \
     *   2     2
     *  / \   / \
     * 4   5 5   4
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    bool result = isSymmetric(root);
    // 输出翻转后的二叉树
    cout<<"isSymmetric: "<< (result== true ? "yes" : "no")<<endl;
    printTree(root);
  
    return 0;
}