class Solution {
public:
    int solve(int idx, vector<int>& dp){
        if(idx==0) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int p=0,p2=0;
        if(idx-2>=0)  p2 = solve(idx-2,dp);
        p=solve(idx-1,dp);
        return dp[idx] = p+p2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n, dp);
    }
};