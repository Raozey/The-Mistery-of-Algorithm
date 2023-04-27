#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a Node.
class TreeNode {
public:
    int val;
    vector<TreeNode*> children;
    TreeNode() {}
    TreeNode(int _val) {
        val = _val;
    }
    TreeNode(int _val, vector<TreeNode*> _children) {
        val = _val;
        children = _children;
    }
};


int maxDepth(TreeNode* root){
    // 递归求最大深度,使用数组
    // if(root == nullptr) return 0;
    // vector<int> linedepth;
    // for(int i = 0; i < root->children.size(); i++){
    //     linedepth.push_back(maxDepth(root->children[i]));
    // }
    // if(linedepth.size() != 0)
    //     return *max_element(linedepth.begin(), linedepth.end()) + 1;   
    // else return 1;

    // 递归求最大深度,使用单个变量
    if(root == nullptr) return 0;
    int depth;
    for(int i = 0; i < root->children.size(); i++){
        depth = max(maxDepth(root->children[i]), depth);
    }
    return depth + 1;
}



int depth = 0;

int main(){
    /**
     * 构造一棵三叉树
     *        1
     *    /   |   \
     *   2    3    4
     *  / \   |
     * 5   6  7    
     * 
     */
// 创建一个3叉树
    TreeNode* root = new TreeNode{1, {}};
    TreeNode* node1 = new TreeNode{2, {}};
    TreeNode* node2 = new TreeNode{3, {}};
    TreeNode* node3 = new TreeNode{4, {}};
    TreeNode* node4 = new TreeNode{5, {}};
    TreeNode* node5 = new TreeNode{6, {}};
    TreeNode* node6 = new TreeNode{7, {}};
    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);
    node1->children.push_back(node4);
    node1->children.push_back(node5);
    node3->children.push_back(node6);

    // 递归法
    depth = maxDepth(root);
    cout<<"MAX depth:"<<depth<<endl;
    return 0;
}