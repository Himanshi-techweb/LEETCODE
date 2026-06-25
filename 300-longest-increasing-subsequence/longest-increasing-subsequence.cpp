class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int prev,vector<int> &nums){
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //check if it prev==-1 || it is larger or equal to prev index number
        int take=INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+solve(i+1,i,nums);
        }
        //if equal then consider it and move to next index and create that index as prev
        int nottake=solve(i+1,prev,nums);
        //but it might be possible that considering it might not get further increasing ok
        return dp[i][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+3,-1));
        return solve(0,-1,nums);
    }
};