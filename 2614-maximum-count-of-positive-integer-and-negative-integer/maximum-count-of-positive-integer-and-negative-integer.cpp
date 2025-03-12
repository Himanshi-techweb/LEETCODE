class Solution {
public:
    int solve(vector<int> &nums,int tar){
        int l=0;int r=nums.size()-1;
        int ans=nums.size();
        while(l<=r){
            int m=l+(r-l)/2;
            if(tar==nums[m]){
                ans=m;
                r=m-1;
            }
            else if(tar<nums[m]){
                ans=m;
               r=m-1;
            }
            else{
                l=m+1;
            }
        }return ans;
    }
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int zero=solve(nums,0);
        int one=solve(nums,1);
        int positive=n-one;
        int negative=zero;
        return max(positive,negative);
    }
};