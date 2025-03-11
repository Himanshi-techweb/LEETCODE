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
     if(sum%2!=0)return false;
        int tar=sum/2;
        vector<vector<bool>> dp(n,vector<bool> (tar+1,false));
        //  return solve(n-1,tar,nums,dp);
        for(int j=0;j<n;j++){
          dp[j][0]=true;
        }
        if(nums[0]<=tar)dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=tar;j++){
                bool nottake=dp[i-1][j];
                bool take=(j>=nums[i])?dp[i-1][j-nums[i]]:false;
                 dp[i][j]=nottake || take; 
            }
        }
        return dp[n-1][tar]; 
    }
};