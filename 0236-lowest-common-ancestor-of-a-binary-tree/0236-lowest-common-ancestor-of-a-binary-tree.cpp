/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        auto la = lowestCommonAncestor(root->left, p, q);
        auto ra = lowestCommonAncestor(root->right, p, q);
        if(la && ra) return root;
        if(la) return la;
        return ra;
        
    }
};