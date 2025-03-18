class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> check(n);
        for(int i=0;i<n;i++){
            check[i]=i;
        } int k=0;int ans=0;
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
              if(arr[i]%arr[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    check[i]=j;
              }
           }
           if(dp[i]>ans){
             k=i;
             ans=dp[i];
           }
        }
       
        vector<int> x;
        while(k!=check[k]){
            x.push_back(arr[k]);
            k=check[k];
        }
        x.push_back(arr[k]);
        reverse(x.begin(),x.end());
        return x;
    }
};