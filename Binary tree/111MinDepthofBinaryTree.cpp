#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "printTree.h"

using namespace std;
int depth = INT32_MAX;

int minDepth(TreeNode* root){
    // 递归求最小深度
    if(root == nullptr) return 0;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if(root->left == nullptr && root->right != nullptr){
        return 1 + rightDepth;
    }
    if(root->right == nullptr && root->left != nullptr){
        return 1 + leftDepth;
    }
    else return min(leftDepth, rightDepth) + 1;
}

void minDepthOrder(TreeNode* root, int index){
    if(root->left == nullptr && root->right == nullptr){
        depth = min(depth, index);
    }
    if(root->left) minDepthOrder(root->left, index + 1); 
    if(root->right) minDepthOrder(root->right, index + 1); 
    return;
}

int levelOrder(TreeNode* root){
    int mincount = 0;
    if(root == nullptr) return mincount;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i<size; i++){
            mincount++;
            TreeNode* cur = que.front();
            que.pop();
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
            if(cur->left == nullptr && cur->right == nullptr)
               return mincount;
        }
    }
    return mincount;
}


int main(){
    /**
     * 构造一棵二叉树
     *     1
     *    / 
     *   2   
     *  / \
     * 4   5
     *      \
     *       5
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(5);
    // 递归法
    // depth = minDepth(root);

    // 前序遍历
    // if(root == nullptr) return 0;
    // minDepthOrder(root, 1);

    //层序遍历
    depth = levelOrder(root);


    cout<<"MIN depth:"<<depth<<endl;
    printTree(root);

    return 0;
}