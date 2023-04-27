#include <iostream>
#include <vector>
#include <stack>

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
    result.push_back(root->val);
    Traversal(root->left, result);
    Traversal(root->right, result);
}
void Iteration(TreeNode* root, vector<int>& result){
    if(root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();
        result.push_back(cur->val);
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
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

    // 递归前序遍历
    // vector<int> result;
    // Traversal(root, result);
    // for(int i : result) cout<<i<<" ";   //1 2 4 5 3    

    // 迭代前序遍历
    vector<int> result;
    Iteration(root, result);
    for(int i : result) cout<<i<<" ";   //1 2 4 5 3   
}