class Solution {
public:
    // int solve(vector<int> &arr,int prev,int curr,int &n,vector<vector<int>> &dp){
    //     if(curr>=n)return 0;
    //     if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
    //     int include=0;
    //     if(prev==-1 || arr[curr]>arr[prev]){
    //         include=1+solve(arr,curr,curr+1,n,dp);
    //     }
    //     int exclude=solve(arr,prev,curr+1,n,dp);
    //     dp[curr][prev+1]=max(include,exclude);
    //     return max(include,exclude);
    // } time complexity is O(n2) and space complexity is O(n2)
    // int solveTab(vector<int> &arr,int n){
    //    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //    for(int curr=n-1;curr>=0;curr--){
    //     for(int prev=curr-1;prev>=-1;prev--){
    //         int include=0;
    //         if(prev==-1 || arr[curr]>arr[prev]){
    //             include=1+dp[curr+1][curr+1];
    //         }
    //         int exclude=dp[curr+1][prev+1];
    //         dp[curr][prev+1]=max(include,exclude);
    //     }
    //    }
    //    return dp[0][0];
    // }time complexity is O(n2) and space complexity is O(n2)
    // int solveTab(vector<int> &arr,int n){
    // //    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //    vector<int> currrow(n+1,0);
    //    vector<int> nextrow(n+1,0);
    //    for(int curr=n-1;curr>=0;curr--){
    //     for(int prev=curr-1;prev>=-1;prev--){
    //         int include=0;
    //         if(prev==-1 || arr[curr]>arr[prev]){
    //             include=1+nextrow[curr+1];
    //         }
    //         int exclude=nextrow[prev+1];
    //         currrow[prev+1]=max(include,exclude);
    //     }
    //     nextrow=currrow;
    //    }
    //    return nextrow[0];
    // }//time complexity is O(n2) and space complexity is O(n)
    int solvemost (vector<int> &arr){
       if(arr.size()==0)return 0;
       vector<int> ans;
       ans.push_back(arr[0]);
       for(int i=1;i<arr.size();i++){
         if(arr[i]>ans.back())ans.push_back(arr[i]);
         else{
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
         }
       }
       return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
    //   vector<vector<int>>dp(n,vector<int> (n+1,-1));
    //   return solve(nums,-1,0,n,dp);  
    return solvemost(nums);
    }
};