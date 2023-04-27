#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include "printTree.h"

using namespace std;

void backtracking(TreeNode* root, string path, vector<string> &result){
    path += to_string(root->val);
    if(root->left == nullptr && root->right == nullptr){
        result.push_back(path);
        return;
    }
    // if(root->left) backtracking(root->left, path+"->", result);
    // if(root->right) backtracking(root->right, path+"->", result);
    // 更直观的写法
    if(root->left) {
        path += "->";
        backtracking(root->left, path, result);
        path.pop_back(); path.pop_back();
    }
    if(root->right) {
        path += "->";
        backtracking(root->right, path, result);
        path.pop_back(); path.pop_back();
    }
}

 
vector<string> binaryTreePaths(TreeNode* root){
    vector<string> result;
    string path;
    if (root == nullptr) return result;
    backtracking(root, path, result);
    return result;
}

int main(){
    /**
     * 构造一棵二叉树
     *      1
     *    /   \
     *   2     3  
     *  / \   /
     * 4   5 5  
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 回溯实现
    vector<string> results;
    results = binaryTreePaths(root);
    

    cout<<" Tree paths: "<<endl;
    for(string it : results) cout<<it<<endl;
    printTree(root);
    return 0;
}