class Solution {
public:
    int ways(int n, int k, vector<vector<int>>& dp, int target){
        if(target==0 && n!=0) return 0;
        if(n==0){
            if(target==0) return 1;
            return 0;
        }
        if(target<0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        int ans = 0;
        for(int i=1; i<=k; i++){
            ans = (ans + ways(n-1, k, dp, target-i))%(int)(1e9+7);
        }
        return dp[n][target] = ans%(int)(1e9+7);
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return ways(n, k, dp, target);
    }
};