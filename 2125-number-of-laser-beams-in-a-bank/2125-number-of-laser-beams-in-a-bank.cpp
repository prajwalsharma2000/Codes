class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0, curr = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bank[i][j] == '1'){
                    curr++;
                }
            }
            if(curr!=0){
                ans += (curr*prev);
                prev = curr;
                curr = 0;
            }
        }
        return ans;
    }
};