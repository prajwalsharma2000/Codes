class Solution {
public:
    int r(int n, vector<int>&dp, vector<int>& nums){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int p = nums[n] + r(n-2, dp, nums);
        int np = r(n-1, dp, nums);
        return dp[n] =  max(p, np);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int p = 0;
            if(i>1) p = nums[i] + dp[i-2];
            else p = nums[i];
            int np = dp[i-1];
            dp[i] = max(p, np);
        }
        return dp[nums.size()-1];
    }
};