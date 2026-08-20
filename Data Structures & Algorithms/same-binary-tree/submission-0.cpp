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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(p);
        st2.push(q);

        while(!st1.empty() && !st2.empty()) {
            TreeNode* node1 = st1.top();
            TreeNode* node2 = st2.top();
            st1.pop(); st2.pop();
            
            if(node1 == NULL && node2 == NULL) continue;
            if(node1 == NULL || node2 == NULL || node1->val != node2->val) return false;

            if(node1 != nullptr) {
                st1.push(node1->left);
                st1.push(node1->right);
                st2.push(node2->left);
                st2.push(node2->right);
            }
        }

        if(!st1.empty() || !st2.empty()) return false;

        return true;
    }
};
