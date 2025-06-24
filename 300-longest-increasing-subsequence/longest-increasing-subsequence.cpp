class Solution {
public:
    // int solve(int i,int prev,vector<int> &arr,vector<vector<int>> &dp){
    //     if(i==arr.size())return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    //     //nottake
    //     int len=solve(i+1,prev,arr,dp);
    //     if(prev==-1 || arr[i]>arr[prev]){
    //         len=max(len,1+solve(i+1,i,arr,dp));
    //     }
    //     return dp[i][prev+1]=len;
    // }
    int lengthOfLIS(vector<int>& arr) {
        vector<vector<int>> dp(arr.size()+1,vector<int> (arr.size()+1,0));
        // return solve(0,-1,arr,dp);
        for(int i=arr.size()-1;i>=0;i--){
            for(int prev=arr.size()-2;prev>=-1;prev--){
                int len=dp[i+1][prev+1];
                if(prev==-1 || arr[i]>arr[prev]){
                   len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][prev+1]=len; 
            }
        }
        return dp[0][0];
    }
};