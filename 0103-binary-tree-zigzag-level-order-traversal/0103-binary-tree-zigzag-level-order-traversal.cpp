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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int round = 0;
        q.push(root);
        while(!q.empty()){
            vector<int> v(q.size());
            int n = q.size(); 
            for(int i=0 ; i<n ; i++){
                auto f = q.front();
                q.pop(); 
                if(round%2==0) v[i] = f->val;
                else v[n-1-i] = f->val;
                    
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            round++;
            ans.push_back(v);
        }
        return ans;
    }
};