/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root, 0, 0);
    }

private:
    vector<int> ids; // 每一层最左边的节点id
    int dfs(TreeNode* node, int d, int id) {
        if(!node) return 0;

        if(d == ids.size()) ids.push_back(id);

        return max({
            id - ids[d] + 1,
            dfs(node -> left, d+1, (id - ids[d])*2),
            dfs(node -> right, d+1, (id-ids[d])*2+1)
        });
    }
};
// @lc code=end

