class Solution {
public:
    int solve(int i,int cnt,vector<int> &arr,vector<vector<int>> &dp){
       if(i>=arr.size())return 0;
       if(dp[i][cnt]!=-1)return dp[i][cnt];
       int take=cnt*arr[i] +solve(i+1,cnt+1,arr,dp);
       int nottake=solve(i+1,cnt,arr,dp);
       return dp[i][cnt]=max(take,nottake); 
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int sum=0;
        int n=satisfaction.size();
        for(int i=0;i<=n;i++){
            sum+=i;
        }
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(0,1,satisfaction,dp);
    }
};