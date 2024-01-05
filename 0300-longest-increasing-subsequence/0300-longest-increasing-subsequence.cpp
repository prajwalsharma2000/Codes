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
        // return lis(n-1, n, n, dp, nums);
        
        for(int i=0; i<n+1; i++) if(i==n || nums[0]<nums[i]) dp[0][i] = 1; else dp[0][i] = 0;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n+1;j++){
                int in=0, nin;
                if(j==n || nums[i]<nums[j]) in = 1 + dp[i-1][i];
                nin = dp[i-1][j];
                dp[i][j] = max(nin, in);
            }
        }
        return dp[n-1][n];
    }
};