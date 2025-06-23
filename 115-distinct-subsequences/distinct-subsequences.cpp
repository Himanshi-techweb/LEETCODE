class Solution {
public:
    int numDistinct(string x, string y) {
       int m=x.size();int n=y.size();
    //    vector<vector<long long>> dp(m+1,vector<long long> (n+1,0));
       vector<unsigned int> prev(n+1,0);
       vector<unsigned int> curr(n+1,0);
       prev[0]=1;curr[0]=1;
    //    for(int i=0;i<=m;i++){
    //     dp[i][0]=1;
    //    }
       for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                curr[j]=prev[j-1]+prev[j];
            }
            else{
                curr[j]=prev[j];
            }
        }
        prev=curr;
       }
       return prev[n];
    }
};