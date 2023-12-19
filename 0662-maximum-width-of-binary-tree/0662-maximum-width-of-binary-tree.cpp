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
    int widthOfBinaryTree(TreeNode* root) {
 queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        int ans = INT_MIN;
        while(!q.empty()){
            int s = q.size();
            int min = q.front().second;
            int first,last;
            for(int i=0;i<s;i++){
                q.front().second= q.front().second-min;
                if(i==0) first = q.front().second;
                if(i==s-1) last = q.front().second;
                if(q.front().first->left!=NULL){
                    q.push({q.front().first->left,2*q.front().second+1});
                }
                if(q.front().first->right!=NULL){
                    q.push({q.front().first->right,2*q.front().second+2});
                }
                q.pop();
            }
            ans= max(ans,last-first+1);
        }
        return ans;
    }
};