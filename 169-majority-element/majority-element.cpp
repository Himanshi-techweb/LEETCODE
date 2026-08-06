class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int it=nums[0];
        int maxcnt=0;
        int ans=-1;
        int i=1;
        while(i<nums.size()){
            if(nums[i]==it)cnt++;
            else{
                cnt--;
                if(cnt==0){
                    it=nums[i];
                    cnt=1;
                }
            }
            i++;
        }
        
        return it;
    }
};