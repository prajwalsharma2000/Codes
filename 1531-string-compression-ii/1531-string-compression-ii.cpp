int dp[101][27][101][101];
class Solution {
public:
    
    int solve(int idx, int prev, int freq, int k, string& s){
        if(idx==0){
            if(k>0) return 0;
            else if(k==0 && s[0]-'a'==prev){
                if(freq==1 || freq==9 || freq==99) return 1;
                else return 0;
            }else{
                return 1;
            }
        }
        if(dp[idx][prev][freq][k]!=-1) return dp[idx][prev][freq][k];
        
        int np= 1e8; 
        if(k>0) np = solve(idx-1, prev, freq, k-1, s);
        int p = 0, addLen = 0;
        
        if(s[idx]-'a'==prev){
            if(freq==1 || freq==9 || freq==99) addLen = 1;
            p = addLen + solve(idx-1, prev, freq+1, k , s);
        }else{
            p = 1 + solve(idx-1, s[idx]-'a', 1, k, s);
        }
        
        return dp[idx][prev][freq][k] = min(p, np);
        
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(n-1, 26, 1, k, s);
    }
};