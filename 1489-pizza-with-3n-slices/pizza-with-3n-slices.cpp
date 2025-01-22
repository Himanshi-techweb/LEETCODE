class Solution {
public:
    int solve(int st,int end,vector<int> &arr,int n,vector<vector<int>> &dp){
        // int prev1=0;
        // int prev2=0;
        // for(int i=st;i<end;i++){
        //    int curr=max(prev2+arr[i],prev1);
        //    prev2=prev1;
        //    prev1=curr;
        // }
        // return prev1;
        if(st>end || n<=0)return 0;
        if(dp[st][n]!=-1)return dp[st][n];
        int include =arr[st]+solve(st+2,end,arr,n-1,dp); 
        int exclude =solve(st+1,end,arr,n,dp); 
        dp[st][n]=max(exclude,include);
        return dp[st][n];
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
       vector<vector<int>>dp1(n,vector<int>(n,-1));
       int case1=solve(0,n-2,slices,n/3,dp1);
       vector<vector<int>>dp2(n,vector<int>(n,-1));
       int case2=solve(1,n-1,slices,n/3,dp2);
       return max(case1,case2); 
    }
};