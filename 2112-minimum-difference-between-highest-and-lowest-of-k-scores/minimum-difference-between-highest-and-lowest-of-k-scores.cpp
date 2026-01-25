class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       if(nums.size()==1)return 0;
    //    return nums[nums.size()-1]-nums[nums.size()-k]; 
    int i=0;int j=k-1;
    int ans=INT_MAX;
    while(j<nums.size()){
      ans=min(ans,nums[j]-nums[i]);
      i++;j++;
    }
    return ans;
    }
};