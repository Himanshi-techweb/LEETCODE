class Solution {
public:
    int solve(int i,vector<int> &arr1,vector<int> &arr2,bool check_swap,vector<vector<int>> &dp){
        if(i>=arr1.size())return 0;
        int ans=INT_MAX;
        int prev1=arr1[i-1];
        int prev2=arr2[i-1];
        if(dp[i][check_swap]!=-1)return dp[i][check_swap];
        if(check_swap)swap(prev1,prev2);
        //swap
        if(prev1<arr1[i] && prev2<arr2[i]){
            ans=solve(i+1,arr1,arr2,0,dp);
        }
        if(prev2<arr1[i] && prev1<arr2[i]){
            ans=min(ans,1+solve(i+1,arr1,arr2,1,dp));
        }
        return dp[i][check_swap]=ans;
    }
    int minSwap(vector<int>&nums1, vector<int>& nums2) {
       nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool check_swap=0;
        vector<vector<int>> dp(nums1.size(),vector<int> (2,-1));
        return solve(1,nums1,nums2,check_swap,dp);
    }
};