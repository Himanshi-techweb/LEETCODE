class Solution {
public://t1=input t2=pattern
    // bool solve(int i,int j,string t1 ,string t2,vector<vector<int>> &dp){
    //     if(i<0 && j<0)return true;
    //     if(j<0 && i>=0)return false;
    //     if(i<0 && j>=0){
    //         for(int k=0;k<=j;k++){
    //             if(t2[k]!='*')return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //matching 
    //     if(t1[i]==t2[j] || t2[j]=='?'){
    //         return dp[i][j]= solve(i-1,j-1,t1,t2,dp);
    //     }
    //     if(t2[j]=='*'){
    //         return dp[i][j]= (solve(i,j-1,t1,t2,dp)|| solve(i-1,j,t1,t2,dp));
    //     }
    //     return dp[i][j]=false;
    // }
    bool isMatch(string t1, string p) {
        int q1=t1.size();
        int q2=p.size();
        vector<vector<int>> dp(q1+1,vector<int> (q2+1,0));
        //return solve(q1-1,q2-1,t1,p,dp);
        dp[0][0]=true;
        for(int i=1;i<=q1;i++){
            dp[i][0]=false;
        }
        for(int j=1;j<=q2;j++){
            dp[0][j]=(p[j-1]=='*' && dp[0][j-1]); 
        }
        for(int i=1;i<=q1;i++){
            for(int j=1;j<=q2;j++){
                //matching 
                if(t1[i-1]==p[j-1] || p[j-1]=='?'){
                   dp[i][j]= dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                   dp[i][j]= dp[i][j-1] || dp[i-1][j];
                }
            }
        }
        return dp[q1][q2];
    }
};