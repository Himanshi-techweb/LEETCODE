class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return {nums[0]};
        int i=1;
        int curr=0;int cnt=1;
        while(i<nums.size()){
            while(i<nums.size() && nums[curr]==nums[i])i++;
            if(curr+1<nums.size() && i<nums.size()){
                nums[curr+1]=nums[i];
                cnt++;
                curr=curr+1;
            }

        }
        
        return cnt;
    }
};