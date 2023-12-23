class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=nums.size()-1, k=0;
        while(i<n && nums[i]==0){i++; k++;}
        while(j>0 && nums[j]==2) j--;
        while(k<=j){
          if(nums[k]==0){
            swap(nums[k], nums[i]);
              if(i==k)k++;
              i++;
            }
            else if(nums[k]==2){
                swap(nums[k], nums[j]);
                j--;
            }
            else
                k++;
        }
    }
};