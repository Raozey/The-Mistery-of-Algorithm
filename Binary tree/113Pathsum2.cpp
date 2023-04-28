#include <iostream>
#include <algorithm>
#include <string>
#include "printTree.h"

using namespace std;
vector<vector<int>> results;
void traversal(TreeNode* root, vector<int> path, int targetSum){
    if(root->left == nullptr && root->right == nullptr){
        if(targetSum == root->val){
            path.push_back(root->val);
            results.push_back(path);
        }
    }
    if(root->left) {
        path.push_back(root->val);
        traversal(root->left, path, targetSum - root->val);
        path.pop_back();
    }
    if(root->right) {
        path.push_back(root->val);
        traversal(root->right, path, targetSum - root->val);
        path.pop_back();
    }
    
}

vector<vector<int>> PathSum(TreeNode* root, int targetSum){
    if(root == nullptr) return results;
    vector<int> path;
    traversal(root, path, targetSum);
    return results;
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
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(42);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    vector<vector<int>> results;

    results = PathSum(root, 7);
    for(vector<int> it : results){
        for(int i : it) cout<<i<<" ";
        cout<<endl;
    }
    printTree(root);
    return 0;
}