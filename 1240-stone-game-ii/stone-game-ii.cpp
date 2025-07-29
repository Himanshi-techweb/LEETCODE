class Solution {
public:
    int n;
    int solveforalice(int person,int i,int m,vector<int> &arr,vector<vector<vector<int>>> &dp){
        if(i>=arr.size())return 0;
        if(dp[person][i][m]!=-1)return dp[person][i][m];
        int result=(person==1)?-1:INT_MAX;
        int stones=0;
        for(int x=1;x<=min(n-i,2*m);x++){
            stones+=arr[i+x-1];
            if(person==1){
                result=max(result,stones+solveforalice(0,i+x,max(m,x),arr,dp));
            }
            else{
                result=min(result,solveforalice(1,i+x,max(m,x),arr,dp));
            }
        }
        return dp[person][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (n+1,vector<int> (2*n +2,-1)));
        return solveforalice(1,0,1,piles,dp);
    }
};