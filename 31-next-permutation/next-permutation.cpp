class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x=nums.size();
        int i=x-2;
      while(i>=0 && nums[i]>=nums[i+1]){
        i--;
      }
      if(i>=0){
        int j=x-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
      }
      reverse(nums.begin()+i+1,nums.end());
       
    }
};