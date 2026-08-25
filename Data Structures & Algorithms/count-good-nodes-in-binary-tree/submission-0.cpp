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
    void helper(TreeNode*root, int &count, int max) {
        if(!root) return;

        if(root->val >= max) {
            count++;
            max = root->val;
        }

        helper(root->left, count, max);
        helper(root->right, count, max);
    }

    int goodNodes(TreeNode* root) {
        int count = 0, max = root->val;
        helper(root, count, max);
        return count;
    }
};
