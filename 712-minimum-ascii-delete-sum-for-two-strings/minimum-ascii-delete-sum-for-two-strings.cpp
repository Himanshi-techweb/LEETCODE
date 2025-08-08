class Solution {
public:
    long long solve(int i,int j,string &x,string &y,vector<vector<long long>> &dp){
        if(i>=x.size()){
            long long check=0;
            while(j<y.size()){
                check+=(int)y[j];
                j++;
            }
            return check;
        }
        if(j>=y.size()){
            long long check=0;
            while(i<x.size()){
                check+=(int)x[i];
                i++;
            }
            return check;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        long long cost=0;
        if(x[i]==y[j]){
            return dp[i][j]=solve(i+1,j+1,x,y,dp);
        }
        return dp[i][j]=min({(int)y[j]+solve(i,j+1,x,y,dp),(int)x[i]+solve(i+1,j,x,y,dp),(int)y[j]+(int)x[i]+solve(i+1,j+1,x,y,dp)});
    }
    int minimumDeleteSum(string s1, string s2) {
        int x1=s1.size();int x2=s2.size();
        vector<vector<long long>> dp(x1+2,vector<long long> (x2+2,-1));
        return solve(0,0,s1,s2,dp);
    }
};