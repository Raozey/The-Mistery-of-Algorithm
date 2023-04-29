#include <algorithm>
#include <vector>
#include "printTree.h"

using namespace std;
TreeNode* consbuildTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return root;
        auto it = find(inorder.begin(), inorder.end(), root->val);

        vector<int> inleft(inorder.begin(), it);
        vector<int> inright(it + 1, inorder.end());

        vector<int> perleft(preorder.begin() + 1, preorder.begin() + 1 + inleft.size());
        vector<int> perright(preorder.begin() + 1 + inleft.size(), preorder.end());

        root->left = consbuildTree(perleft, inleft);
        root->right = consbuildTree(perright, inright);
        return root;

}

int main(){
    /**1
     * 从前序与中序遍历序列构造二叉树
     * 用前序的第一个节点取划分中序
     * preorder [3,9,20,15,7]
     * inorder [9,3,15,20,7]
     *      3     
     *    /   \
     *   9    20
     *       /   \
     *      15    7
     */
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder  = {9,3,15,20,7};
    TreeNode* root = consbuildTree(preorder, inorder);
    printTree(root);
    return 0;
}
