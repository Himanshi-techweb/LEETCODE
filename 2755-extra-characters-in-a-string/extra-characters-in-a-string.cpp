class Solution {
public:
    int solve(int start,string s,unordered_set<string> &st,vector<int> &dp){
        if(start>=s.size())return 0;
        if(dp[start]!=-1)return dp[start];
        string str="";
        int mini=s.size();
        for(int i=start;i<s.size();i++){
           str.push_back(s[i]);
           if(st.find(str)!=st.end()){
            mini=min(mini,solve(i+1,s,st,dp));
           }
           else{
            mini=min(mini,(int)str.size()+solve(i+1,s,st,dp));
           }
        }
        return dp[start]=mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for(auto it:dictionary)st.insert(it);
        vector<int> dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};