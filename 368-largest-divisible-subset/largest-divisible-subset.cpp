class Solution {
public:
    int solve(int i,int prev,vector<int> &arr){
        if(i==arr.size())return 0;
        int len=solve(i+1,0,arr);
        if(prev==-1 || (i==prev+1 && ( arr[i]%arr[prev]==0 || arr[prev]%arr[i]==0))){
            len=1+solve(i+1,i,arr);
        }
        return len;
    }
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> back(n);
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)back[i]=i;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(((arr[i]%arr[prev]==0) || (arr[prev]%arr[i]==0)) && dp[i]<1+dp[prev]){
                    back[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
        }int maxi=dp[0];int ix=0;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                ix=i;
            }
        }
        ans.push_back(arr[ix]);
        while(ix!=back[ix]){
          ix=back[ix];
          ans.push_back(arr[ix]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};