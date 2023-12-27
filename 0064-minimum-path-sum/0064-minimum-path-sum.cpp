class Solution {
public:
    int ps(int i, int j, vector<vector<int>> dp, vector<vector<int>> &grid){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e8;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = grid[i][j] + ps(i-1, j , dp, grid);
        int top = grid[i][j] + ps(i, j-1, dp, grid);
        return dp[i][j] = min(left, top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else{
                int l=1e5,t=1e5;
                if(i>0) l = grid[i][j] + dp[i-1][j];
                if(j>0) t = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(l,t);
                }
            }
        }
        return dp[m-1][n-1];
    }
};