/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3
*/

// 深度优先搜索DFS deep first search
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // 一直比较左右子树的深度
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++res;
            int n = q.size();
            // 把本层节点的子节点取出来放到队列，然后下一次循环下一次的所有子节点，取出子节点的所有子子节点……
            for (int i = 0; i < n; ++i) {
                TreeNode *t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
