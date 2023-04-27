#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include "printTree.h"

using namespace std;

void traversal(TreeNode* root, int& result){
    if(root->left != nullptr && root->left->left ==nullptr && root->left->right ==nullptr) {
        result += root->left->val;
    }
    if(root->left) traversal(root->left, result);
    if(root->right) traversal(root->right, result);
}

int countleft(TreeNode* root){
    int result = 0;
    if(root == nullptr) return result;
    traversal(root, result);
    return result;

}
int sumofLeftLeaves(TreeNode* root){
    if(root == nullptr) return 0;
    int left = 0;
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
        left = root->left->val;
    }
    return left + sumofLeftLeaves(root->left) + sumofLeftLeaves(root->right);

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
    // int sum = countleft(root);
    int sum = sumofLeftLeaves(root);

    cout<<" Left Leaf Sum: "<<sum<<endl;
    printTree(root);
    return 0;
}