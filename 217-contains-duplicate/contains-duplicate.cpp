class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int,int> check;
      int i=0;
      while(i<nums.size()){
        check[nums[i]]++;
        if(check[nums[i]]>1)return true;
        i++;
      }
      return false;  
    }
};