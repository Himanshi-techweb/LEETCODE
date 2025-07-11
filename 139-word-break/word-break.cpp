class Solution {
public:
    bool solve(int i,unordered_set<string> &st,string &x,vector<int> &dp){
       if(i>=x.size())return true;
       if(dp[i]!=-1)return dp[i];
       for(int j=i;j<x.size();j++){
            if(st.find(x.substr(i,j-i+1))!=st.end()){
              if(solve(j+1,st,x,dp)) return dp[i]= true;
              }
            }
       
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> st;
      for(auto it :wordDict)st.insert(it);
      vector<int> dp(s.size(),-1);
      return solve(0,st,s,dp);
    }
};