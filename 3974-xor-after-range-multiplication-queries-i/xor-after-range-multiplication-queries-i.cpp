class Solution {
public:
    const int MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int k=queries[i][2];
            int u=queries[i][3];
            int j=l;
            while(j<=r ){
               nums[j]=(1LL*nums[j]*u)%(MOD);
               nums[j]=nums[j]%MOD;
               j+=k;
            }
        }
        int ans=0;
        for(auto it:nums)ans=ans^it;
        return ans;
    }
};