class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]]++;
        }
        
        int ans=0;
        
        for(auto map : m){
            cout<<map.first<<" "<<map.second<<endl;
            if(map.second == 1) return -1;
            else{
                    if(map.second%3==1) ans+=1;
                        ans += map.second/3;
                        map.second = map.second%3;
                        ans += map.second/2;
            }
        }
        return ans;
    }
};