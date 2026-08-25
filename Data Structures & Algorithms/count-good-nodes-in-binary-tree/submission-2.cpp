/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode*root, int max) {
        if(!root) return 0;

        int res = 0;

        if(root->val >= max) {
            res += 1;
            max = root->val;
        }

        res += helper(root->left, max);
        res += helper(root->right, max);

        return res;
    }

    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};
