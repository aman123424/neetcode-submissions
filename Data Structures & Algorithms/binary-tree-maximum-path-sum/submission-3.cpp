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
    int dfs(TreeNode* root, int &ans) {
        if(!root) return 0;

        int leftMax = max(dfs(root->left, ans), 0);
        int rightMax = max(dfs(root->right, ans), 0);
        ans = max(ans, root->val + leftMax + rightMax);

        return (root->val + max(leftMax, rightMax));
    }

    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        dfs(root, ans);
        return ans;
    }
};
