#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "printTree.h"

using namespace std;

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };



TreeNode * reverseTree(TreeNode * root){
    // 方法一下到上翻转
    // if(root == nullptr) return root;
    // TreeNode* left = reverseTree(root->left);
    // TreeNode* right = reverseTree(root->right);  
    // root->right = left;
    // root->left = right;
    // return root;

    // 方法二从上到下翻转
    if(root == nullptr) return root;
    swap(root->left, root->right);
    reverseTree(root->left);
    reverseTree(root->right);
    return root;

}


int main(){
    /**
     * 构造一棵二叉树
     *     1
     *    / \
     *   2   3
     *  / \
     * 4   5
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root = reverseTree(root);

    // 输出翻转后的二叉树
    printTree(root);
    //    1__     
    //  /   \
    // 3     2
    //      / \
    //     5   4



    return 0;
}