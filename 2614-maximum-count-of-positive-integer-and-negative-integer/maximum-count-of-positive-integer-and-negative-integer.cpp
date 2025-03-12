class Solution {
public:
    // int solve(int l,int r,vector<int> &nums){
    //     if(l<0 || r>=nums.size())return 0;
    //     int m=(l+r)/2;
    //     while(nums[m]==0)
    // }
    int maximumCount(vector<int>& nums) {
        int l=0;int r=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]<0)l++;
          if(nums[i]>0)r++;
        }
        return max(l,r);
    }
};