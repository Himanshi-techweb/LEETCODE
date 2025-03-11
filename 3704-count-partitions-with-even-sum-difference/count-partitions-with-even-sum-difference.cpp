class Solution {
public:
    int countPartitions(vector<int>& nums) {
      vector<int> check(nums.size(),0);
      check[0]=nums[0];
      for(int i=1;i<nums.size();i++){
        check[i]=check[i-1]+nums[i];
      }
      int i=1;
      int ans=0;
      while(i<nums.size()) {
        int left=check[i];
        int right=check[nums.size()-1]-check[i];
        if(abs(right-left)%2==0){
            ans++;
        }
        i++;
      } return ans;
    }
};