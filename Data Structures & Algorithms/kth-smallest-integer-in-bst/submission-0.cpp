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
    void helper(TreeNode* root, vector<int> &elements) {
        if(!root) return;

        helper(root->left, elements);
        elements.push_back(root->val);
        helper(root->right, elements);
    }

    int kthSmallest(TreeNode* root, int k) {
       vector<int> elements;
       helper(root, elements); 

       return elements[k - 1];
    }
};
