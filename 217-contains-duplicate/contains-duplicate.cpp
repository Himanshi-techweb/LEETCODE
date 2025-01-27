class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> check;
      int i=0;
      while(i<nums.size()){
        if(check.count(nums[i]))return true;
        check.insert(nums[i]);
        i++;
      }
      return false;  
    }
};