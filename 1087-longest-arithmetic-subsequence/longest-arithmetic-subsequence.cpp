class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
       vector<vector<int>> dp(nums.size(),vector<int>(1001,0));
       int maxlen=0;
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            int diff=nums[i]-nums[j]+500;
            dp[i][diff]=(dp[j][diff]>0)?dp[j][diff]+1:2;
            maxlen=max(maxlen,dp[i][diff]);
        }
       }
       return maxlen;
    }
};