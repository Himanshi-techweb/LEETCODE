class Solution {
public:
    int solve(int i,int j,string t1,string t2, vector<vector<int>> &dp){
        if(j<=0)return 1;
        if(i<=0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i-1]==t2[j-1]){
           return  dp[i][j]=solve(i-1,j-1,t1,t2,dp)+solve(i-1,j,t1,t2,dp);
        }
        else{
            return dp[i][j]=solve(i-1,j,t1,t2,dp);
        }
    }
    int numDistinct(string t1, string t2) {
       int q1=t1.size();
       int q2=t2.size();
       vector<vector<unsigned long long>> dp(q1+1,vector<unsigned long long> (q2+1,0ULL));
       for(int i=0;i<=q1;i++){
         dp[i][0]=1;
       }
    //    return solve(q1,q2,t1,t2,dp); 
    vector<double> prev(q2+1,0),curr(q2+1,0);
    prev[0]=curr[0]=1;

    for(int i=1;i<=q1;i++){
        for(int j=q2;j>=1;j--){
            if(t1[i-1]==t2[j-1]){
               prev[j]=prev[j-1]+prev[j];
            }
            else{
                 prev[j]=prev[j];
            }
        }
        //prev=curr;
    }
    return (int)prev[q2];//typecast return double to int
    }
};