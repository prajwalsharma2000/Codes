class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        for(auto map: m){
            if(s.find(map.second)!=s.end()) return false;
            s.insert(map.second);
        }
        return true;
    }
};