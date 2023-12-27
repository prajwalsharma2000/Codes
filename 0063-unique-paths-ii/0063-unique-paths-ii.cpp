class Solution {
public:
    int up(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &og){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(og[i][j] == 1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = up(i-1, j, dp, og);
        int top = up(i, j-1, dp, og);
        return dp[i][j] = left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return up(m-1, n-1, dp, obstacleGrid);
    }
};