#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // 迭代法
    // while (root)
    // {
    //     if(root->val > p->val && root->val > q->val) root = root->left;
    //     else if (root->val < p->val && root->val < q->val) root = root->right;
    //     else return root;
    // }
    // return nullptr;

    //递归法
    if(root == nullptr) return nullptr;
    else if(root->val > p->val && root->val > q->val)  return lowestCommonAncestor(root->left, p, q);
    else if(root->val < p->val && root->val < q->val)  return lowestCommonAncestor(root->left, p, q);
    else return root;

    
    

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
     * 寻找4和9的最近公共祖先
     */
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    TreeNode* p =  root->left->left;
    root->left->right = new TreeNode(9);
    TreeNode* q =  root->left->right;
    root->left->right->right = new TreeNode(10);


    
    TreeNode* result = lowestCommonAncestor(root,p,q);

    cout<<"lowestCommonAncestor: "<<(result == nullptr ? "no": to_string(result->val))<<endl;
    printTree(root);
    return 0;
}