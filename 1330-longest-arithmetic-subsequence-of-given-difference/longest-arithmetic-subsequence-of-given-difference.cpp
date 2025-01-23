class Solution {
public:
    // int solve(int i,vector<int> &arr,int &diff,vector<int> &dp){
    //    if(i>=arr.size())return 0;
    //    if(dp[i]!=-1)return dp[i];
    // //    if(arr[i]-arr[i-1]==diff){
    // //     ans=max(ans,1+solve(i+1,arr,diff,dp));
    // //    }
    // int ans=0;
    // for(int i=1;i<arr.size();i++){
    //     ans=0;
    //    if(arr[i]-arr[i-1]==diff){
    //     ans=max(ans,1+dp[i-1]);
    //     dp[i]=ans;
    //    } 
    // }
    //    return dp[arr.size()-1];
    // }
        
    
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int curr=arr[i]-diff;
            int count=0;
            if(dp.count(curr)){
                count=dp[curr];
            }
            dp[arr[i]]=1+count;
            ans=max(dp[arr[i]],ans);
        }return ans;
    }
};