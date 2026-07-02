class Solution {
public:
    long long ans=INT_MIN;
    vector<vector<long long>> dp;
    long long solve(int extra,int count){
        if(extra==0 ){
            if(count>=2)return 1;
            else return 0;
        }
        if(dp[extra][count]!=-1)return dp[extra][count];
        long long maxproduct=0;
        for(int i=1;i<=extra;i++){
           long long product=1LL*i*solve(extra-i,count+1);  
           maxproduct=max(maxproduct,product); 
        }
        return dp[extra][count]=maxproduct;
    }
    int integerBreak(int n) {
        dp.resize(60,vector<long long>(60,-1));
        return solve(n,0);
        
    }
};