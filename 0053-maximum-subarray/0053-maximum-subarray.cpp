class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT_MIN, s = 0;
        for(int i=0;i<nums.size(); i++){
            s += nums[i];
            if(s>m){
                m = s;
            }
            if(s<0){
                s = 0;
            }
        }
        return m;
    }
};