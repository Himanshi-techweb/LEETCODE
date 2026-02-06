class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int right=0;int ans=nums.size();
      for(int left=0;left<nums.size();left++){
        while(right<nums.size() && nums[right]<=(long long)nums[left]*k){
            right++;
        }
        ans=min(ans,(int)nums.size()-right+left);
      }  
      return ans;
    }
};

// 1   2  6   9
