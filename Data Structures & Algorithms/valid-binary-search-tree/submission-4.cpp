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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        queue<tuple<TreeNode*, long, long>> qu;
        qu.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while(!qu.empty()) {
            auto [node, left, right] = qu.front();
            qu.pop();

            if(!(left < node->val && right > node->val)) return false;

            if(node->left) {
                qu.push(make_tuple(node->left, left, node->val));
            }
            if(node->right) {
                qu.push(make_tuple(node->right, node->val, right));
            }
        }

        return true;
    }
};
