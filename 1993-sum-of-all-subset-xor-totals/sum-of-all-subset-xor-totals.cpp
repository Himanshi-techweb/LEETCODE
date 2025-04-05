class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
      int ans=0;
      int n=nums.size();
      int total=1<<n;
      for (int mask = 0; mask < total; ++mask) {
        int xorVal = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                xorVal ^= nums[i];
            }
        }
        ans+=xorVal;
     }
     return ans;
    }
};