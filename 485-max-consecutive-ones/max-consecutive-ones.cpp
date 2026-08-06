class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int i=0;
       while(i<nums.size() && nums[i]==0)i++;
       //now i that which is 1
       int maxcnt=0;int cnt=0;
       while(i<nums.size()){
        if(nums[i]==0){
            maxcnt=max(maxcnt,cnt);
            cnt=0;
        }
        else cnt++;
        i++;
       }

       maxcnt=max(maxcnt,cnt);
       return maxcnt;

    }
};