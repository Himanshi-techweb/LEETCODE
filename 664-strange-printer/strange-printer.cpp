class Solution {
public:
    vector<vector<int>>dp;
    int solve(int l,int r,string &s){
        if(l>r)return 0;
        if(l==r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];
        int i=l;i++;
        while(i<s.size() && s[i]==s[l])i++;
        if(i==r+1)return 1;
        int basic=1+solve(i,r,s);
        int res=INT_MAX;
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int ans=solve(i,j-1,s)+solve(j,r,s);
                res=min(res,ans);
                
            }
            
        }
        return dp[l][r]=min(res,basic);
        
    }
    int strangePrinter(string s) {
        dp.resize(101,vector<int>(101,-1));
        return solve(0,s.size()-1,s);
    }
};