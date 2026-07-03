class Solution {
public:
    vector<vector<int>> dp;
    long long solve(int i,int day,vector<int>&arr){
        if(i>=arr.size()){
            if(day<=0)return 0;
            return INT_MAX;
        }

        if(dp[i][day]!=-1)return dp[i][day];
        long long take=0;int maxi=0;
        long long ans=INT_MAX;
        for(int k=i;k<arr.size();k++){
            maxi=max(maxi,arr[k]);
            if(day-1>=0){take=maxi+(long long)solve(k+1,day-1,arr);
            ans=min(ans,take);}
        }
        return dp[i][day]=ans;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)return -1;
        dp.resize(jobDifficulty.size()+11,vector<int>(d+10,-1));
        return solve(0,d,jobDifficulty);
    }
};