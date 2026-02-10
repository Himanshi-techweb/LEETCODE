class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        vector<int> check(1e5 + 5 ,-1);
        for(int i=0;i<nums.size();i++){
        int even=0;int odd=0;
        for(int j=i;j<nums.size();j++){
            if(check[nums[j]]<i){
               check[nums[j]]=i;
               if(nums[j]%2==0)even++;
               else odd++;
            }   
            if(even==odd)ans=max(ans,j-i+1);
        }
        
      }
      return ans;
    }
};