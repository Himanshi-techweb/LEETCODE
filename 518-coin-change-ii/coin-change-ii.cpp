class Solution {
public:
    
    int change( int amount,vector<int>& arr) {
        int n=arr.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long> (amount+1,0LL));
        
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int i=arr[0];i<=amount;i++){
            if(i%arr[0]==0)dp[0][i]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                unsigned long long take=0LL;
                if(arr[i]<=a)take=dp[i][a-arr[i]];//it is the number of ways to make that coin not the minimum number of coin as we already adding how to make amount-arr[i] then n require to add 1 there
                unsigned long long nottake=dp[i-1][a];
                dp[i][a]=take+nottake;
            }
        }
          return (dp[n-1][amount]>INT_MAX) ?0:dp[n-1][amount];
    }
};