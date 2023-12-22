class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int n1=0, n2=0, ans=INT_MIN;
        for(char c: s) if(c=='1') n1++;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1')n1--;
            else n2++;
            ans = max(ans, n1+n2);
        }
        return ans;
    }
};