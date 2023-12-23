class Solution {
public:
    void generateRows(int row, vector<int>& v){
        v.push_back(1);
        int f = 1;
        for(int col=1; col<row; col++){
            f = f*(row-col);
            f = f/col;
            v.push_back(f);
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1; row<=numRows; row++){
            vector<int> v;
            generateRows(row, v);
            ans.push_back(v);
        }
        return ans;
    }
}; 