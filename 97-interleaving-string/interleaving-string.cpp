class Solution {
public:
    bool check(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int>>> &dp){
        if(i>=s1.size() && j>=s2.size() && k<s3.size())return false;
        if(i>=s1.size() && j>=s2.size() && k>=s3.size())return true;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool ans=false;
        if(s1[i]==s3[k]){
           ans=ans|| check(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k]){
            ans=ans||check(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j][k]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int size1=s1.size();int size2=s2.size();int size3=s3.size();
        if(size1+size2!=size3)return false;
        vector<vector<vector<int>>> dp(size1 +1,vector<vector<int>>(size2 +1,vector<int> (size3 +1,-1)));
        return check(0,0,0,s1,s2,s3,dp);
    }
};