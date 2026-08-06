class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int e=0;int o=1;int i=0;
       vector<int> ans(nums.size());
       while(i<nums.size()  ){
        if(nums[i]>0){
            //even
            ans[e]=nums[i];
            e+=2;
        }
        else{
            ans[o]=nums[i];
            o+=2;
        }
        i++;
       }
       return ans; 
    }
};