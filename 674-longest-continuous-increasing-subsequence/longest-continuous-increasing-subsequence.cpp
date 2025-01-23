class Solution {
public:
    // int solve(vector<int> &arr,int prev,int curr,vector<vector<int>>&dp){
        // if(curr>=arr.size() )return 0;
        // if(dp[curr][prev+1]!=-1){
        //     return dp[curr][prev+1];
        // }
        // int include=0;
        // if(prev==-1 || arr[curr]>arr[prev]){
        //     include=1+solve(arr,curr,curr+1,dp);
        // }
        // int exclude=solve(arr,curr+1,curr+2,dp);
        // return dp[curr][prev+1]=max(include,exclude);

    // }
    int findLengthOfLCIS(vector<int>& arr) {
    if(arr.size()<=1)return arr.size();
    //  vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    //  return solve(nums,-1,0,dp)  ;
     int ans=0;
     for(int i=0;i<arr.size()-1;i++){
        int j=i+1;
        int count=1;
        while(j<arr.size() && arr[j]>arr[j-1]){
            count++;
            j++;
        }
        ans=max(ans,count);
     }return ans;
    }
};