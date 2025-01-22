class Solution {
public:
    // int solveMem(int i,vector<int>&arr1,vector<int>&arr2,bool check_swap,vector<vector<int>>&dp){
    //     if(i>=arr1.size())return 0;
    //     int ans=INT_MAX;
    //     int prev1=arr1[i-1];
    //     int prev2=arr2[i-1];
    //     if(dp[i][check_swap]!=-1)return dp[i][check_swap];
    //     if(check_swap)swap(prev1,prev2);
    //     //swap
    //     if(prev1<arr1[i] && prev2<arr2[i]){
    //         ans=solve(i+1,arr1,arr2,0,dp);
    //     }
    //     if(prev2<arr1[i] && prev1<arr2[i]){
    //         ans=min(ans,1+solve(i+1,arr1,arr2,1,dp));
    //     }
    //     return dp[i][check_swap]=ans;
    // }

    int solveTab(vector<int>&arr1,vector<int>&arr2){
        vector<vector<int>> dp(arr1.size()+1,vector<int>(2,0));
        for(int i=arr1.size()-1;i>=1;i--){
            for(int check=1;check>=0;check--){ 
                   int ans=INT_MAX; 
                   int prev1=arr1[i-1];
                   int prev2=arr2[i-1];
                   if(check)swap(prev1,prev2);
                   //swap
                   if(prev1<arr1[i] && prev2<arr2[i]){
                    ans=dp[i+1][0];
                   }
                   if(prev2<arr1[i] && prev1<arr2[i]){
                    ans=min(ans,1+dp[i+1][1]);
                   }
                   dp[i][check]=ans;
            }
        }return dp[1][0];
    }


    int minSwap(vector<int>&nums1, vector<int>& nums2) {
       nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool check_swap=0;
        // vector<vector<int>> dp(nums1.size(),vector<int> (2,-1));
        // return solve(1,nums1,nums2,check_swap,dp);
        return solveTab(nums1,nums2);
    }
};