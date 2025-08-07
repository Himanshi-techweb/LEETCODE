class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
       int m=arr.size();
       vector<int> dp(m,1);
       vector<int> count(m,1);
       int maxi=1;
       for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                    maxi=max(maxi,dp[i]);
                }
                else if(dp[j]+1==dp[i]){
                    count[i]=count[i]+count[j];
                }
            }    
        }
        
       }
       int ans=0;
       for(int i=0;i<m;i++){
        if(dp[i]==maxi)ans+=count[i];
       }
       return ans;
    }
};