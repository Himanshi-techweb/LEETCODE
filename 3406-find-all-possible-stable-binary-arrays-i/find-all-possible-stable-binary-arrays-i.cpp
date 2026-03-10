class Solution {
public:
    const int MOD = 1'000'000'007;
    int ans=0;
    int check(int countzero,int countone,int limit,int zero,int one,int back,vector<vector<vector<int>>> &dp){
       //
       if(countzero==zero && countone==one){
        return 1;
       } 
       if(countzero>zero || countone>one)return 0;

       if(dp[countzero][countone][back]!=-1)return dp[countzero][countone][back];
       int count=0;
       //check if back is zero or one 
       //if one then start loop from 1 to limit

       if(back){
        for(int i=1;i<=limit;i++){
            count=(count +check(countzero+i,countone,limit,zero,one,0,dp)%MOD)%MOD;
        }
       }
       else{
        for(int i=1;i<=limit;i++){
            count=(count+check(countzero,countone+i,limit,zero,one,1,dp)%MOD)%MOD;
        }
       }
       return dp[countzero][countone][back]=count;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+10,vector<vector<int>>(one+10,vector<int>(2,-1)));
        for(int i=1;i<=limit;i++){
          ans+=check(i,0,limit,zero,one,0,dp);
          ans=ans%MOD;
        }
        for(int i=1;i<=limit;i++){
           ans+=check(0,i,limit,zero,one,1,dp);
           ans=ans%MOD;
        }
        return ans;
    }
};