#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Traversal(TreeNode* root, vector<int>& result){
    if(root == nullptr) return;
    Traversal(root->left, result);
    result.push_back(root->val);
    Traversal(root->right, result);
}
void Iteration(TreeNode* root, vector<int>& result){
    if(root == nullptr) return;
    stack<TreeNode*> st;
    while(root != nullptr || !st.empty()){
        if(root != nullptr){
            st.push(root);
            root = root->left;
        }else{
            root = st.top();
            st.pop();
            result.push_back(root->val);
            root = root->right;
        }
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

    // 递归中序遍历
    // vector<int> result;
    // Traversal(root, result);
    // for(int i : result) cout<<i<<" ";   //4 2 5 1 3    

    // 迭代中序遍历
    vector<int> result;
    Iteration(root, result);
    for(int i : result) cout<<i<<" ";   //4 2 5 1 3   
}
