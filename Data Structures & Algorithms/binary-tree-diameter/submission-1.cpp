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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        stack<TreeNode*> st;
        unordered_map<TreeNode*, pair<int, int>> mp;
        mp[nullptr] = {0, 0};

        st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();

            if(curr->left && mp.find(curr->left) == mp.end()) {
                st.push(curr->left);
            } else if(curr->right && mp.find(curr->right) == mp.end()) {
                st.push(curr->right);
            } else {
                curr = st.top();
                st.pop();

                auto[leftHeight, leftDiameter] = mp[curr->left];
                auto[rightHeight, rightDiameter] = mp[curr->right];

                int height = 1 + max(leftHeight, rightHeight);
                int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

                mp[curr] = {height, diameter};
            }
        }

        return mp[root].second;
    }
};
