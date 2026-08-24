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
    bool isEqual(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) return true;

        if(r1 == NULL || r2 == NULL || r1->val != r2->val) return false;

        return isEqual(r1->left, r2->left) && isEqual(r1->right, r2->right); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        TreeNode* curr = root;
        stack<TreeNode*> st;

        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            if(isEqual(curr, subRoot)) return true;
            curr = curr->right;
        } 

        return false;
    }
};
