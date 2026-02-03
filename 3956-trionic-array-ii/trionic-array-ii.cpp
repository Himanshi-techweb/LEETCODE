class Solution {
public:
    typedef long long ll;
    const ll MIN=-1e18;
    int n;
    ll solve(vector<int> &arr,int i,int state,vector<vector<ll>> &dp){
        //state =0 (increasing)   state=1 (decreasing)     state=2 (increasing)
        if(i==n){
            // if(state==2 )return 0;
            return MIN;
        }
            ll ans=MIN;
            if(dp[i][state]!=-1)return dp[i][state]; 
            //increasing
            if(state==0 && arr[i]>arr[i-1]){
                ans=max(ans,arr[i]+solve(arr,i+1,0,dp));
                ans=max(ans,arr[i]+solve(arr,i+1,1,dp));
            }

            //decreasing
            else if(state==1 && arr[i]<arr[i-1]){
                ans=max(ans,arr[i]+solve(arr,i+1,1,dp));
                ans=max(ans,arr[i]+solve(arr,i+1,2,dp));
            }

            //increasing
            else if(state==2 && arr[i]>arr[i-1]){
                ans=max(ans,arr[i]+solve(arr,i+1,2,dp));
                ans=max(ans,(ll)arr[i]);
            }
        // }
        return dp[i][state]=ans;
    }
    long long maxSumTrionic(vector<int>& nums) {
        n=nums.size();
        ll ans=MIN;
        vector<vector<ll>> dp(n+1,vector<ll>(3,-1));
        for(int i=0;i<nums.size()-1;i++){
            ans=max(ans,nums[i]+solve(nums,i+1,0,dp));
        }
        return ans;
    }
};