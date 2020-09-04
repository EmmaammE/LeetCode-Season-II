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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        traverse(root, "", paths);

        return paths;
    }

    void traverse(TreeNode* root, string path, vector<string>& paths) {
        if(root != nullptr) {
            path += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr) {
                paths.push_back(path);
                return;
            }

            path += "->";
            traverse(root->left, path, paths);
            traverse(root->right, path, paths);
        }
    }
};