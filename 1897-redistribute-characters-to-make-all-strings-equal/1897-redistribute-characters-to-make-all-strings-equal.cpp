class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n==0||n==1) return true;
        vector<int> v(26, 0);
        for(string word: words){
            for(char letter: word) v[letter-'a']++;
        }
        for(int i=0;i<26;i++) if(v[i]==0 || v[i]%n==0) continue; else return false;
        return true;
    }
};