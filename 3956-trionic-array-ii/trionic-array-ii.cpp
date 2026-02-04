class Solution {
public:
    typedef long long ll;
    const ll MIN=-1e18;
    int n;
    ll solve(int i,vector<int> &arr,int state,vector<vector<ll>>&dp){
        if(i==arr.size())return MIN;
        if(dp[i][state]!=-1)return dp[i][state];
        ll ans=MIN;
        // if(state==0 && i==0){
        //     ans=max(ans,arr[i]+solve(i+1,arr,state,dp));
        //     ans=max(ans,arr[i]+solve(i+1,arr,state+1,dp));
        // }
        if(state==0 && arr[i]>arr[i-1]){
            ans=max(ans,arr[i]+solve(i+1,arr,state,dp));
            ans=max(ans,arr[i]+solve(i+1,arr,state+1,dp));
        }
        else if(state==1 && arr[i]<arr[i-1]){
            ans=max(ans,arr[i]+solve(i+1,arr,state,dp));
            ans=max(ans,arr[i]+solve(i+1,arr,state+1,dp));
        }
        else if(state==2 && arr[i]>arr[i-1]){
            ans=max(ans,arr[i]+solve(i+1,arr,state,dp));
            ans=max(ans,(ll)arr[i]);
        }
        return dp[i][state]=ans;
    }
    long long maxSumTrionic(vector<int>& nums) {
        n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(3,-1));
        ll ans=MIN;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,nums[i]+solve(i+1,nums,0,dp));
        }
        return ans;
    }
};