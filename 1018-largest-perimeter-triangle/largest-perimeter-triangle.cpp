class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int i=0;int j=1;int k=2;
        sort(nums.begin(),nums.end());
        int maxi=0;
        while(k<nums.size()){
            if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[j]+nums[k]>nums[i]){
                maxi=max(maxi,nums[i]+nums[j]+nums[k]);
                
            }
            i++;j++;k++;
            
        }
        return maxi;
    }
};