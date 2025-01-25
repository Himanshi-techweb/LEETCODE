class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n=nums.size();
      unordered_map<int,int> check;
      for(auto x:nums){
        check[x]++;
      }
      for(auto x:check){
        if(x.second>1)return x.first;
      }
      return 0;
    }
};