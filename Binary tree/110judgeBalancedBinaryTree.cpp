#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;


int getdepth(TreeNode* root){
    if(root == nullptr) return 0;
    int left = getdepth(root->left);
    if(left == -1 ) return -1;
    int right = getdepth(root->right);
    if(right == -1) return -1;
    return abs(right - left) > 1 ? -1 : 1 + max(left, right);
}


bool judgeBalance(TreeNode* root){
    return getdepth(root) == -1 ? false : true;
}

int main(){
    /**
     * 构造一棵二叉树
     *      1
     *    /   
     *   2      
     *  / \   
     * 4   5  
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bool judge = judgeBalance(root);
    
    cout<<" Tree is balanced tree: "<<(judge == true ? "yes" : "no")<<endl;
    printTree(root);
    return 0;
}