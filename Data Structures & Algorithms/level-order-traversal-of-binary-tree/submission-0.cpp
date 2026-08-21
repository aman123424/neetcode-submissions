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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == nullptr) return {};

        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 1});

        vector<int> currNodes;
        int currLevel = 1;

        while(!qu.empty()) {
            TreeNode* curr = qu.front().first;
            int level = qu.front().second;
            qu.pop();

            if(level == currLevel) {
                currNodes.push_back(curr->val);
            } else {
                res.push_back(currNodes);
                currNodes.clear();
                currLevel = level;
                currNodes.push_back(curr->val);
            }

            if(curr->left) qu.push({curr->left, level + 1});
            if(curr->right) qu.push({curr->right, level + 1});
        }

        res.push_back(currNodes);
        return res;
    }
};
