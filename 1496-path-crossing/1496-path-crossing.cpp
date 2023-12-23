class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> p;
        p.insert("(0,0)");
        int i=0, j=0;
        for(char c: path){
            if(c=='N') j++;
            else if(c=='S') j--;
            else if(c=='E') i++;
            else i--;
            string s = "(" + to_string(i) + "," + to_string(j) + ")";
            if(p.find(s)!=p.end()) return true;
            else p.insert(s);
        }
        return false;
    }
};