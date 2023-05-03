#include <iostream>
#include <algorithm>
#include "printTree.h"

using namespace std;


void intraversal(TreeNode* root, vector<int> & result){
    if(root == nullptr) return;
    intraversal(root->left, result);
    result.push_back(root->val);
    intraversal(root->right, result);
}

bool isSearchBST(TreeNode* root){
    vector<int> result;
    intraversal(root, result);
    for(int i = 1; i < result.size(); i++){
        if(result[i] <= result[i-1]) return false;
    }
    return true;
}

//中序遍历的过程中记录节点的数值大小 
long long maxVal = LONG_MIN;
// 这个方法有点难理解，建议画图多思考一下递归的过程
// 简而言之是直接搜到最右边的叶子节点，叶子节点为根节点的树肯定是搜素二叉树(只有一个节点)
// 然后再返回到最左边的叶子节点的父节点，看以这个节点为根节点的树是不是搜索二叉树，以此类推。
bool  isValidBST(TreeNode* root){
    if(root == nullptr) return true;

    bool left = isValidBST(root->left);
    if(maxVal < root->val) maxVal = root->val;
    else return false;

    bool right = isValidBST(root->right);
    return left && right;
}


// 也可以记录前一个节点
TreeNode* pre = nullptr; 
bool isValidBST(TreeNode* root) {
    if(root == nullptr) return true;
    if(pre != nullptr && pre->val >= root->val) return false;
    bool left = isValidBST(root->left);
    pre = root;
    bool right = isValidBST(root->right);
    return left && right;
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
     *       18
     */
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(18);
    //中序遍历得到的数组必须是严格升序
    // bool result = isSearchBST(root);

    // 递归方法
    bool result =  isValidBST(root);
    cout<<"is Search BST:"<<( result == true ? "yes" : "no")<<endl;
    printTree(root);

    return 0;
}
