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
    int sol(TreeNode* root){
        if(root==NULL) return 10e5;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + min(sol(root->left), sol(root->right));
        
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return sol(root);
    }
};