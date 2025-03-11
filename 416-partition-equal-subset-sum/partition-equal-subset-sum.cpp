class Solution {
public:
    bool solve(int i,int tar,vector<int> &arr,vector<vector<int>> &dp){
        if(tar==0)return true;
        if(i==0)return arr[0]==tar;
        if(dp[i][tar]!=-1)return dp[i][tar];
        bool nottake=solve(i-1,tar,arr,dp);
        bool take=(tar>=arr[i])?solve(i-1,tar-arr[i],arr,dp):false;
        return dp[i][tar]=nottake || take;
    }
    bool canPartition(vector<int>& nums) {
     int sum=0;
     for(auto x:nums){
        sum+=x;
     } 
     int n=nums.size();
     if(sum%2==0){
        int tar=sum/2;
        vector<vector<int>> dp(n,vector<int> (tar+1,-1));
         return solve(n-1,tar,nums,dp);
     }
     else{
        return false;
     }  
    }
};