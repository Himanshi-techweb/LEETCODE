class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int count=0;int maxcount=0;
       for(int i=0;i<nums.size();i++){
        if(count==0 && nums[i]==1)count++;
        else if(nums[i]==0){
            maxcount=max(maxcount,count);count=0;
        }
        else count++;
       } 
       maxcount=max(maxcount,count);
       return maxcount;
    }
};