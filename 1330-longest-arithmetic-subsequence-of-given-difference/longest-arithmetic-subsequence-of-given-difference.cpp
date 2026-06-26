class Solution {
public:
    // int solve(int i,int diff,vector<int> &arr){
//
    // }
    int longestSubsequence(vector<int>& arr, int difference) {
         unordered_map<int,int> dp;
        // vector<int> dp(arr.size()+1,-1);
        int ans=1;
        for(int i=0;i<arr.size();i++){
            if(dp.count(arr[i]-difference)){
                dp[arr[i]]=1+dp[arr[i]-difference];
            }
            else{
                dp[arr[i]]=1;
            }
            ans=max(ans,dp[arr[i]]);
        }
        return ans;

    }
};