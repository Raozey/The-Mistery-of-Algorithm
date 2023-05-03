#include <iostream>
#include <algorithm>
#include <string>
#include "printTree.h"

using namespace std;
int result = false;
void traversal(TreeNode* root, int targetSum){
    if(root->left == nullptr && root->right == nullptr){
        if(targetSum == root->val){
            result = true;
            return;
        }
    }
    if(root->left) traversal(root->left, targetSum - root->val);
    if(root->right) traversal(root->right, targetSum - root->val);
}


//踩坑记：当你想要递归到叶子节点的下一个节点（空节点），需要在root == nullptr后返回
void traversal(TreeNode* root, int targetSum){
    if(root == nullptr) {
       if(targetSum == 0) {
            result = true;
            return;
       } 
       return;
    }
    traversal(root->left, targetSum - root->val);
    traversal(root->right, targetSum - root->val);
}

bool traversalWithReturn(TreeNode* cur, int count){
    if(!cur->left && !cur->right && count == 0) return true;
    if (!cur->left && !cur->right) return false;

    if(cur->left){
        count -= cur->left->val; // 递归，处理节点;
        if (traversalWithReturn(cur->left, count)) return true;
        count += cur->left->val; // 回溯，撤销处理结果
    }
    if(cur->right){
        count -= cur->right->val; // 递归，处理节点;
        if (traversalWithReturn(cur->right, count)) return true;
        count += cur->right->val; // 回溯，撤销处理结果
    }
    return false;
}



bool hasPathSum(TreeNode* root, int targetSum){
    // if(root == nullptr) return result;
    // traversal(root, targetSum);
    // return result;

    if(root == nullptr) return false;
    return traversalWithReturn(root, targetSum- root->val);
}
// 迭代精简代码
// bool hasPathSum(TreeNode* root, int sum) {
//     if (!root) return false;
//     if (!root->left && !root->right && sum == root->val) {
//         return true;
//     }
//     return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
// }


// 用栈来实现前序遍历
bool haspathsum_stack(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    // 此时栈里要放的是pair<节点指针，路径数值>
    stack<pair<TreeNode*, int>> st;
    st.push(pair<TreeNode*, int>(root, root->val));
    while (!st.empty()) {
        pair<TreeNode*, int> node = st.top();
        st.pop();
        // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
        if (!node.first->left && !node.first->right && sum == node.second) return true;
        // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if (node.first->right) {
            st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
        }
        // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
        if (node.first->left) {
            st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
        }
    }
    return false;
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

    bool sum  = hasPathSum(root, 7);

    cout<<"Path sum of"<< " 7 "<<(sum == true ? "yes" : "no")<<endl;
    printTree(root);
    return 0;
}
