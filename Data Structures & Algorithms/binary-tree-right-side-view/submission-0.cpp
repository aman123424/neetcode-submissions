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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 1});
        int currLevel = 1;

        while(!qu.empty()) {
            TreeNode* curr = qu.front().first;
            int level = qu.front().second;
            qu.pop();

            if(curr) {
                if(currLevel == level) {
                    result.push_back(curr->val);
                    currLevel++;
                }

                qu.push({curr->right, level + 1});
                qu.push({curr->left, level + 1});
            }
        }

        return result;
    }
};
