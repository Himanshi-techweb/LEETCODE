class Solution {
public:
    int m,n;
    vector<pair<int,int>> rc={{0,1},{1,0}};
    vector<vector<vector<int>>> dp;
    int coin(int i,int j,vector<vector<int>> &coins,int neu){
        if(i>=m || j>=n)return INT_MIN;
        if(i==m-1 && j==n-1){
            if(coins[i][j]>=0)return dp[i][j][neu]=coins[i][j];
            else {
                if(neu>0)return dp[i][j][neu]= max(0,coins[i][j]);
                return dp[i][j][neu]= coins[i][j];
            }
        } 
        if(dp[i][j][neu]!=-1)return dp[i][j][neu];
        int ans=INT_MIN;
        int next=0;
        for(auto it:rc){
            int nr=it.first+i;
            int nc=it.second+j;
            if(nr<m && nc<n){
               next=coin(nr,nc,coins,neu);
               if(next!=INT_MIN)
               {if(coins[i][j]>=0)ans=max(ans,next+coins[i][j]);
               else{
                 ans=max(ans,coins[i][j]+next);
                 if(neu>0){
                    int next2=coin(nr,nc,coins,neu-1);
                    ans=max(next2,ans);
                 }
               }
               }
            }
        }
        // if(dp[i][j])
        //if negative then neu 
       
        return dp[i][j][neu]=ans;


    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();n=coins[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        // return coin(0,0,coins,2);
        for(int k=2;k>=0 ;k--){
            if(coins[m-1][n-1]>0)dp[m-1][n-1][k]=coins[m-1][n-1];
            else{
                if(k>0)dp[m-1][n-1][k]=max(0,coins[m-1][n-1]);
                else dp[m-1][n-1][k]=coins[m-1][n-1];
            }
        }

        for(int i=m-1;i>=0 ;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)continue;
                for(int k=0;k<=2;k++){
                    int best=INT_MIN;
                    if(j+1<n){
                        int next=dp[i][j+1][k];
                        if(next!=INT_MIN){
                            if(coins[i][j]>=0)best=max(best,coins[i][j]+next);
                            else{
                                best=max(best,coins[i][j]+next);
                                if(k>0){
                                    int next2=dp[i][j+1][k-1];
                                    if(next2!=INT_MIN)best=max(best,next2);
                                }
                            }
                        }
                    } 

                    if(i+1<m){
                        int next=dp[i+1][j][k];
                        if(next!=INT_MIN){
                            if(coins[i][j]>=0)best=max(best,next+coins[i][j]);
                            else{
                                best=max(next+coins[i][j],best);
                                if(k>0){
                                    int next2=dp[i+1][j][k-1];
                                    if(next2!=INT_MIN)best=max(best,next2);
                                }
                            }
                        }
                    }

                    dp[i][j][k]=best;
                }
            }
        }
        return dp[0][0][2];
    }
};