class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(int i,int j,int k,string x,string y,string z){
        if(k>=z.size() && i>=x.size() && j>=y.size())return dp[i][j][k]= true;
        if(i>=x.size() && j>=y.size())return dp[i][j][k]= false;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        //x and z equal 
        if(i<x.size() && x[i]==z[k]){
            if(solve(i+1,j,k+1,x,y,z))return dp[i][j][k]= true;
        }

        //y and z
        if(j<y.size() && y[j]==z[k]){
            if(solve(i,j+1,k+1,x,y,z))return dp[i][j][k]= true;
        }

        return dp[i][j][k]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(101,vector<vector<int>>(101,vector<int>(201,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};