#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include "printTree.h"

using namespace std;
int depth = INT32_MAX;

int countPlain(TreeNode* root){
    if(root == nullptr) return 0;
    return countPlain(root->left) + countPlain(root->right) + 1;
}

int countComplete(TreeNode* root){
    if(root == nullptr) return 0;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int depthleft = 0, depthright = 0;
    while(left) {
        left = left->left;
        depthleft++;
    }
    while(right){
        right = right->right;
        depthright++;
    }
    if(depthleft == depthright) return pow(2,depthleft + 1)- 1;
    
    return countComplete(root->left) + countComplete(root->right) + 1;
}

int main(){
    /**
     * 构造一棵二叉树
     *      1
     *    /   \
     *   2     3  
     *  / \   /
     * 4   5 5  
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // 求普通二叉树的节点数目
    // int count = countPlain(root);

    // 满二叉树的节点数目为（2^树的深度-1）
    int count = countComplete(root);

    cout<<" Complete Tree Nodes: "<<count<<endl;
    printTree(root);
    return 0;
}