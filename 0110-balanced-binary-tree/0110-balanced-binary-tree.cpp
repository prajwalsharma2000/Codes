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
    bool sol = true;
    int bal(TreeNode* root){
        if(root==NULL) return 0;
        int lh = bal(root->left);
        int rh = bal(root->right);
        if(abs(lh-rh)>1) sol = false;
        return 1+max(lh,rh);
        
    }
    bool isBalanced(TreeNode* root) {
        bal(root);
        return sol;
    }
};