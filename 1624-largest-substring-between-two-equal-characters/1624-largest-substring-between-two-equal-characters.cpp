class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int arr[26];
        int sol = -1;
        for(int i=0;i<26;i++) arr[i] = -1;;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a'] == -1) arr[s[i]-'a'] = i;
            else{
                sol = max(sol,i - arr[s[i]-'a'] - 1);
            }
        }
        return sol;
    }
};