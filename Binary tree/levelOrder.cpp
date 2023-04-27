#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Iteration(TreeNode* root, vector<vector<int>>& results){
    if(root == nullptr) return;
    queue<TreeNode*> que; 
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> result;
        for(int i = 0; i < size; i++){
            TreeNode* cur = que.front();
            que.pop();
            result.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        results.push_back(result);
    }
}

int main(){
    /**
     * 构造一棵二叉树
     *     1
     *    / \
     *   2   3
     *  / \
     * 4   5
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 迭代层序遍历
    vector<vector<int>> results;
    Iteration(root, results);
    for(auto result : results)  {
        for(int i : result) cout<<i<<" "; 
        cout<<endl;
    }
    // 1 
    // 2 3 
    // 4 5 
}