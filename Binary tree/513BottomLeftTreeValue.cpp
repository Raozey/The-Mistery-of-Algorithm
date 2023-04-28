#include <iostream>
#include <algorithm>
#include <string>
#include "printTree.h"

using namespace std;
int result = 0;
int maxdepth = INT32_MIN;

void traversal(TreeNode* root, int depth){
    if(root->left == nullptr && root->right == nullptr){
        if(depth > maxdepth){
            maxdepth = depth;
            result = root->val;
            return;
        }
    }
    if(root->left) traversal(root->left, depth+1);
    if(root->right) traversal(root->right, depth+1);
}

int findBottomLeftValue(TreeNode* root){
    if(root == nullptr) return result;
    traversal(root, 1);
    return result;
}
int  levelfindBottomLeftValue(TreeNode* root) {
    // 层序遍历
    int result = 0;
    if(root == nullptr) return result;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i<size; i++){
            TreeNode* cur = que.front();
            que.pop();
            if(i == 0)result = cur->val;
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
    }
    return result;
}


int main(){
    /**
     * 构造一棵二叉树
     *       1
     *    /    \
     *   2      3  
     *  / \    /
     * 4   5  5  
     *       /
     *      42
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->left->left = new TreeNode(42);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int value = levelfindBottomLeftValue(root);

    cout<<"Bottom Left Value: "<<value<<endl;
    printTree(root);
    return 0;
}