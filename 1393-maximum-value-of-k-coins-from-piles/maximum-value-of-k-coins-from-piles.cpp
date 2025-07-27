class Solution {
public:
    int solve(int row,vector<vector<int>> &arr,int n,int k,vector<vector<int>> &dp){
        if(k==0)return 0;
        if(row>=n)return 0;
        if(dp[row][k]!=-1)return dp[row][k];
        int nottake=solve(row+1,arr,n,k,dp);

        int sum=0;int take=INT_MIN;
        for(int i=0;i<min(k,(int)arr[row].size());i++){
           sum+=arr[row][i];
           if(k-(i+1)>=0){
            take=max(take,sum+solve(row+1,arr,n,k-(i+1),dp));
           }
        }
        
        return dp[row][k]= max(take,nottake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
      int n=piles.size(); 
      vector<vector<int>> dp(n,vector<int>(k+1,-1));
      return solve(0,piles,n,k,dp);  
    }
};