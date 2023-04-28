#include <iostream>
#include <vector>
#include <algorithm>
#include "printTree.h"

using namespace std;
vector<int> result;

int maxcount = INT_MIN;
int mycount = 0;
int base;

void update(int x){
    if(x == base)  mycount++;
    else{
        mycount = 1;
        base = x;
    }
    if(mycount == maxcount){
        result.push_back(x);
    }
    else if(mycount > maxcount){
        maxcount = mycount;
        result.clear();
        result.push_back(x);
    }

}

void dfs(TreeNode* root){
    if(root ==nullptr) return;
    dfs(root->left);
    update(root->val);
    dfs(root->right);
}

vector<int> findmost(TreeNode* root){
    dfs(root);
    return result;
}


void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // 前序遍历
    if (cur == nullptr) return ;
    map[cur->val]++; // 统计元素频率，中左右
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return;
}

void findMode(TreeNode* root){
    unordered_map<int, int> umap; // key:元素，value:出现频率
    if(root == nullptr) return;
    searchBST(root, umap);
    vector<pair<int, int>> vec(umap.begin(), umap.end());
    auto cmp = [](pair<int, int>a, pair<int, int>b)
                 {return a.second > b.second;};
    sort(vec.begin(), vec.end(), cmp);//按照频率降序排列
    result.push_back(vec[0].first);
    for(int i =1; i < vec.size(); i++){
        if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
        else break;
    }
}

int main(){
    /**
     * 构造一棵二叉搜索树
     *     12
     *    / \
     *   4   30
     *  / \
     * 4   9
     *      \
     *       9
     */
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(4);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->left->right->right = new TreeNode(9);


    // 递归方法
    // findmost(root); 
    
    // 遍历统计方法
    findMode(root);

    cout<<"Minimum Difference: ";
    for(int i : result)  cout<<i<<" ";
    cout<<endl;
    printTree(root);
    return 0;
}