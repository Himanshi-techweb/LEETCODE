class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> ans(nums.size());
       vector<int> prefix(nums.size()); 
       vector<int> suffix(nums.size());
       prefix[0]=nums[0]; 
       for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]*nums[i];
       }
       suffix[nums.size()-1]=nums[nums.size()-1];
       for(int i=nums.size()-2;i>=0;i--){
        suffix[i]=suffix[i+1]*nums[i];
       }
       ans[0]=suffix[1];
       ans[nums.size()-1]=prefix[nums.size()-2];
       for(int i=1;i<nums.size()-1;i++){
          ans[i]=prefix[i-1]*suffix[i+1];
       }
       return ans;
    }
};