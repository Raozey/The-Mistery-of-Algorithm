// Code Originate From:
// https://blog.csdn.net/weixin_41990671/article/details/108885298
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * 中序遍历返回节点数组
 * @param root 根节点
 * @return 中序遍历节点数组
 */
std::vector<TreeNode *> inorderTraversal(TreeNode *root) {
    std::vector<TreeNode *> res;
    std::stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root);
        root = root->right;
    }
    return res;
}


/**
 * 利用下划线和正反斜杠打印出美观的二叉树，没有破坏二叉树结构，但传入的root会有变化
 * @param root  二叉树根节点
 */
void printTree(TreeNode *root) {
    if (!root)return;
    auto tmp = root;
    std::vector<TreeNode *> intv = inorderTraversal(tmp);//中序遍历节点数组
    std::string template_str;//模板string，表示每行打印string的长度
    int location = 0;
    std::unordered_map<TreeNode *, int> first_locations;//存储节点对应在本行string中的首位置
    for (auto &i : intv) {
        location = template_str.size();
        template_str += std::to_string(i->val) + " ";
        first_locations[i] = location;
    }
    for (auto &i:template_str)i = ' ';//把模板全部置为空格方便后续使用
    //层序遍历
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        std::string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            cur_loc = first_locations[node];
            std::string num_str = std::to_string(node->val);
            //左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
            if (node->left) {
                q.push(node->left);
                int first_loc = first_locations[node->left] + 1;
                tmp_str2[first_loc++] = '/';
                while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

            }
            //中间,对应位置打印节点值（有可能为多位数）
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
            if (node->right) {
                q.push(node->right);
                int last_loc = first_locations[node->right] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //打印两行
        std::cout << tmp_str1 << std::endl;
        std::cout << tmp_str2 << std::endl;
    }
}

