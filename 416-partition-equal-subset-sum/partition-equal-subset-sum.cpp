class Solution {
public:
    bool solve(int i,int sum,int tar,vector<int> &arr,vector<vector<int>> &dp){
        if(sum==tar)return true;
        if(i>=arr.size()|| sum>tar)return false;
        
        if(dp[i][sum]!=-1){
            return dp[i][sum]==1?true:false;
        }
        bool take=solve(i+1,sum+arr[i],tar,arr,dp);
        bool nottake=solve(i+1,sum,tar,arr,dp);
        dp[i][sum]=((take|| nottake)==true?1:0);
        return dp[i][sum];
    }
    bool canPartition(vector<int>& arr) {
      int sum=0;
      for(auto x:arr){
        sum+=x;
      }
      if(sum%2!=0)return false;
      int tar=sum/2;
      vector<vector<int>> dp(arr.size()+1,vector<int> (tar+1,-1));
      return solve(0,0,tar,arr,dp);
    }
};