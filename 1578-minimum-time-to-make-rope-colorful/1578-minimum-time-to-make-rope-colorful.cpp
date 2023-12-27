class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =0;;
        int n = colors.size();
        char c = colors[0];
        for(int i=1; i<n; i++){
            if(colors[i]==colors[i-1]){
                int m = neededTime[i-1];
                ans+=neededTime[i-1];
                while(i<n && colors[i]==colors[i-1]){
                    m = max(m, neededTime[i]);
                    ans+=neededTime[i];
                    i++;
                }
                ans-=m;
                i--;
            }
        }
        return ans;
    }
};