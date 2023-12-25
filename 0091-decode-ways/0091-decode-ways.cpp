class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        int c1 = 1;
        int c2 = 1;
        for(int i=1; i<s.size(); i++){
            int n1 = s[i]-'0';
            int n2 = (s[i-1]-'0')*10+ n1;
            int c = 0;
            if(n1>0) c+=c1;
            if(n2>=10 && n2<=26) c+=c2;
            c2=c1;
            c1=c;
        }
        return c1;
    }
};