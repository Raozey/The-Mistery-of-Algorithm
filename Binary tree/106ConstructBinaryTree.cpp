#include <algorithm>
#include <vector>
#include "printTree.h"

using namespace std;
TreeNode* consbuildTreetructMaximumBinaryTree(vector<int>& inorder, vector<int>& postorder){
    if(postorder.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(postorder.back());
    if(postorder.size() == 1) return root;
    postorder.pop_back();
    auto it = find(inorder.begin(), inorder.end(), root->val);

    vector<int> inleft(inorder.begin(), it);
    vector<int> inright(it + 1, inorder.end());
    vector<int> postleft(postorder.begin(), postorder.begin() + inleft.size());
    vector<int> postright(postorder.begin() + inleft.size(), postorder.end());

    root->left = consbuildTreetructMaximumBinaryTree(inleft, postleft);
    root->right = consbuildTreetructMaximumBinaryTree(inright, postright);
    return root;
}

int main(){
    /**
     * 从中序与后序遍历序列构造二叉树
     * 用后序的最后一个节点取划分中序
     * inorder [9,3,15,20,7]
     * postorder [9,15,7,20,3]
     *      3     
     *    /   \
     *   9    20
     *       /   \
     *      15    7
     */
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder  = {9,15,7,20,3};
    TreeNode* root = consbuildTreetructMaximumBinaryTree(inorder, postorder);
    printTree(root);
    return 0;
}
