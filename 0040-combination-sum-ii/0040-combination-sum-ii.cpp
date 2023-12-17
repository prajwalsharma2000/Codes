class Solution {
public:
vector<vector<int>> sol;
void combination(int idx, int tar, vector<int>& v, vector<int>& candidates){
    if(idx == candidates.size()){
        if(tar==0) sol.push_back(v);
        return;
    }
    if(tar>0){
        v.push_back(candidates[idx]);
        combination(idx+1, tar-candidates[idx], v, candidates);
        v.pop_back();
    }
    while(candidates.size()>1 && idx<=candidates.size()-2 && candidates[idx+1] == candidates[idx]) idx++;

    combination(idx+1, tar, v, candidates);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combination(0, target, v, candidates);
        return sol;
    }
};