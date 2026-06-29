class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &x,string &y){
        if(i>=x.size() && j>=y.size())return 0;
        if(i>=x.size()){
            int num=0;
            for(auto k=j;k<y.size();k++){
                num=num+y[k];
            }
            return num;
        }
        if(j>=y.size()){
            int num=0;
            for(int k=i;k<x.size();k++){
                num=num+x[k];
            }
            return num;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int res=0;
        // int match=INT_MIN;int notmatch=INT_MAX;
        //if both are equal then go to next index
        if(x[i]==y[j])res+=solve(i+1,j+1,x,y);
        else res+=min({y[j]+solve(i,j+1,x,y),x[i]+solve(i+1,j,x,y),x[i]+y[j]+solve(i+1,j+1,x,y)});
        return dp[i][j]=res;
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2);
    }
};