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
    Traversal(root->right, result);
    result.push_back(root->val);
}
void Iteration(TreeNode* root, vector<int>& result){
    // 思路：先得到中右左的序列后反转
    if(root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();
        result.push_back(cur->val);
        if(root->left) st.push(cur->left);
        if(root->right) st.push(cur->right);
    }
    reverse(result.begin(), result.end());
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

    // 递归后序遍历
    // vector<int> result;
    // Traversal(root, result);
    // for(int i : result) cout<<i<<" ";   //4 5 2 3 1     

    // 迭代后序遍历
    vector<int> result;
    Iteration(root, result);
    for(int i : result) cout<<i<<" ";   //4 5 2 3 1   
}
