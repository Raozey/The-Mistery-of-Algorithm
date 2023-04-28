#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;

TreeNode* deleteNode(TreeNode* root, int key){
    // 普通二叉树的删除方式
    if(root == nullptr) return root;
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    if(root->val == key){
        if(root->right == nullptr) return root->left;
        if(root->left == nullptr) return root->right;
        TreeNode *cur = root->right;
        while(cur->left) cur = cur->left;
        cur->left = root->left;
        return root->right;
    }
    return root;
}


TreeNode* deleteBSTNode(TreeNode* root, int key){
    if (root == nullptr) return root;
    if (root->val > key){
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->val < key){
        root->right = deleteNode(root->right, key);
        return root;
    }
    else{ //root->val < key
        if(root->left == nullptr && root->right == nullptr){
            root = nullptr;
            return root;
        }
        if(root->left == nullptr){
            root = root->right;
            return root;
        }
        if(root->right == nullptr){
            root = root->left;
            return root;
        }
        //待删除的节点左右节点都不为空
        // 把左子树移动到右子树的最底层最左边的叶子的左节点，
        // root的位置由右子树节点代替  
        TreeNode* newnode = root->right;
        while(newnode->left)  newnode = newnode->left;
        newnode->left = root->left;
        root = root->right;
        return root;
    }
    return root;

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
     */
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(10);
 
    TreeNode* result = deleteBSTNode(root, 12);
    printTree(result);
    return 0;
}