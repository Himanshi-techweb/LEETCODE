class Solution {
public:
    int solve(int idx,int day,vector<int> &arr,vector<vector<int>> &dp,int n){
        if(idx<0)return 0;
        if(day==1){
            int maxD=arr[idx];
            for(int i=idx;i<n;i++){
                maxD=max(maxD,arr[i]);
            }
            return maxD;
        }
        if(dp[idx][day]!=-1)return dp[idx][day];
        int maxD=arr[idx];int finalans=INT_MAX;
        for(int i=idx;i<n-day+1;i++){
            maxD=max(maxD,arr[i]);
            int result=maxD+solve(i+1,day-1,arr,dp,n);
            finalans=min(finalans,result);
        }
        return dp[idx][day]=finalans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d)return -1;
        vector<vector<int>> dp(n+1,vector<int> (d+1,-1));
        return solve(0,d,jobDifficulty,dp,n);
       
    }
};