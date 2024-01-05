class Solution {
public:
    int lis(int idx, int prev, int n, vector<vector<int>>& dp, vector<int>& nums){
        if(idx==0){
            if(prev==n || nums[0]<nums[prev]) return 1;
            return 0;
        }
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int in=0, nin;
        if(prev==n || nums[idx]<nums[prev]) in = 1 + lis(idx-1, idx, n, dp, nums);
        nin = lis(idx-1, prev, n, dp, nums);
        return dp[idx][prev] = max(nin, in);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return lis(n-1, n, n, dp, nums);
    }
};