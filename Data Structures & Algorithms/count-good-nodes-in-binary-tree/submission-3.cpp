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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, INT_MIN});
        int count = 0;

        while(!qu.empty()) {
            TreeNode* curr = qu.front().first;
            int maxVal = qu.front().second;
            qu.pop();

            if(curr->val >= maxVal) {
                count++;
                maxVal = curr->val;
            } 

            if(curr->left) {
                qu.push({curr->left, maxVal});
            }

            if(curr->right) {
                qu.push({curr->right, maxVal});
            }
        } 

        return count;
    }
};
