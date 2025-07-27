class Solution {
public:
    int solve(int curr,int pre,string &s,int n,vector<vector<int>> &dp) {
    if(curr==s.size())return 0;
    if(dp[curr][pre+1]!=-1)return dp[curr][pre+1];
    int flip=INT_MAX;int not_flip=INT_MAX;

    int ch=s[curr]-'0';
    if(pre==-1 || ch>=pre)not_flip=solve(curr+1,ch,s,n,dp);
    int change=(ch==0)?1:0;
    if(pre==-1 || change>=pre){
        flip=1+solve(curr+1,change,s,n,dp);
    }
    return dp[curr][pre+1]=min(flip,not_flip);
}

    int minFlipsMonoIncr(string s) {

        int n=s.size();
        // if(n==1)return 0;
        // vector<vector<int>> dp(n+1,vector<int> (3,-1));
        // return solve(0,-1,s,n,dp);
        
        int count_1=0;int flip=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'){
              count_1++;
            }
            else{
               flip=min(flip+1,count_1); 
            }
        }
        return flip;

    }
};