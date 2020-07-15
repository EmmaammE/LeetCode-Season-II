/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> nodes{to_delete.begin(), to_delete.end()};

        function<TreeNode*(TreeNode*)> del = [&](TreeNode* n) -> TreeNode* {
            if(!n) return nullptr;

            if(n->left) n->left = del(n->left);
            if(n->right) n->right = del(n->right);

            if(!nodes.count(n->val)) return n; 

            if(n->left) ans.push_back(n->left);
            if(n->right) ans.push_back(n->right);

            return nullptr;
        };

        TreeNode* r = del(root);
        if(r) ans.push_back(r);

        return ans;
    }
};
// @lc code=end

