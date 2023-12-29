
class Solution {
public:
    
    int solve(int idx, int amount,vector<vector<int>> &dp, vector<int>& coins){
        if(idx==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e7;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int p = 1e7, np;
        if(coins[idx]<=amount) p = 1+solve(idx, amount-coins[idx], dp, coins);
        np = solve(idx-1, amount, dp, coins);
        return dp[idx][amount] = min(p, np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  solve(n-1, amount, dp, coins);
        if(ans>=1e7) return -1;
        return ans;
    }
};