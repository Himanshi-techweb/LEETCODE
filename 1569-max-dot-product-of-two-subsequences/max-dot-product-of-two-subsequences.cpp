class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int> &x,vector<int>&y){
        if(i==x.size() || j==y.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int cal=x[i]*y[j];
        int take_i_j=INT_MIN;
        if(solve(i+1,j+1,x,y)!=INT_MIN)take_i_j=x[i]*y[j]+solve(i+1,j+1,x,y);
        int take_i=solve(i,j+1,x,y);
        int take_j=solve(i+1,j,x,y);
        return dp[i][j]=max({cal,take_i_j,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return solve(0,0,nums1,nums2);
    }
};