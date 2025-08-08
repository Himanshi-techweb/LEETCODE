class Solution {
public:
    bool solve(int i,vector<int> &arr,int n,vector<int> &dp){
       //base case
        if(i>=n)return true;
        if(dp[i]!=-1)return dp[i];
       //check for condition 1
       if(i+1<n && arr[i]==arr[i+1] && solve(i+2,arr,n,dp))return dp[i]=true;

       //condition 2
       if(i+2<n && arr[i+1]==arr[i] && arr[i+2]==arr[i+1] && solve(i+3,arr,n,dp))return dp[i]=true;
       
       //condition 3
       if(i+2<n && arr[i+1]==arr[i]+1 && arr[i+2]==arr[i+1]+1 && solve(i+3,arr,n,dp))return dp[i]=true;
       return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        if(nums.size()==2){
            if(nums[0]==nums[1])return true;
            return false;
        }
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,nums.size(),dp);
    }
};