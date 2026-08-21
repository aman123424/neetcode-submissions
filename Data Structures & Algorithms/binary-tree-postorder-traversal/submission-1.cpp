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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || !st.empty()) {
            while(curr) {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->right;
            }

            curr = st.top();
            st.pop();
            curr = curr->left;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};