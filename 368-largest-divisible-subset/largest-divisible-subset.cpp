class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
       vector<int> dp(n,1); 
       vector<int> check(n);
       for(int i=0;i<n;i++){
        check[i]=i;
       }
       int ix=0;int ans=0;
       sort(arr.begin(),arr.end());
       for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                check[i]=j;
            }
        }
        if(ans<dp[i]){
            ans=dp[i];
            ix=i;
        }
       }
       vector<int> result;
       while(ix!=check[ix]){
         result.push_back(arr[ix]);
         ix=check[ix];
       }
       result.push_back(arr[ix]);
       //reverse(result.begin(),result.end());
       return result;
    }
};