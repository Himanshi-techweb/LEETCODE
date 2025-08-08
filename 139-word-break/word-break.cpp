class Solution {
public:
    
    bool solve(int start,string s,unordered_map<string,bool> &check,vector<int> &dp){
        if(start>=s.size())return true;
        if(dp[start]!=-1)return dp[start];
        for(int i=start;i<s.size();i++){
            string str=s.substr(start,i-start+1);
            if(check.find(str)!=check.end()){
                if(solve(i+1,s,check,dp))return dp[start]= true;
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<int> dp(s.size(),-1);
      unordered_map<string,bool> check;
      for(auto it:wordDict){
        check[it]=false;
      }
      return solve(0,s,check,dp);
    }
};