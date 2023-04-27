// 二叉书用c++写的结构体
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), , left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// 二叉树的种类
1、满二叉树：每个节点的度为0或者2，并且所有度为0的节点再同一层（最底层）。
2、完全二叉树：除最底层外，其他层必须全部填满，且最底层的节点要集中再该层的左边若干位置。
   若最底层是第n层，该层含有的节点数为[1,2^(n-1)]
3、二叉搜索树，是一棵有序树， 左<中<右。
4、平衡二叉搜索树，左右子树的高度差不超过1，并且左右子树都是一棵平衡二叉搜索树。
5、红黑树，
6、b树，
7、b+树，

  
