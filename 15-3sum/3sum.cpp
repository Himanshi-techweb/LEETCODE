class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //   if(nums.size()==3){
    //     if(nums[0]+nums[1]+nums[2]==0){
    //         return {{nums[0],nums[1],nums[2]}};
    //     }
    //     else{
    //         return {};
    //     }
    //   }
      vector<vector<int>> ans;
      sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1;int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<0){
                    l++;
                }
                else if(sum>0){
                   r--;
                }
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;
                    while(l<r && nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
            }
        }

     return ans; 
    }
   
};