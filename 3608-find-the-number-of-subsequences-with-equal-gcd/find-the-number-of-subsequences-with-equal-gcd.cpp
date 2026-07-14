class Solution {
public: 
    const int MOD=1E9 +7;
    vector<vector<vector<int>>>dp;
    // unordered_map<pair<int,pair<int,pair<int,int>>>>q;
    // map<tuple<int,int,int>,int>q;
    int solve(int i,vector<int>&arr,int g1,int g2){
        if(i==arr.size()){
            
            return (g1!=0 && g2!=0 && g1==g2);
        }
        if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];
        int ans=0;
        //take it for sub1 
        
        ans=(ans+(solve(i+1,arr,gcd(g1,arr[i]),g2))%MOD)%MOD;
        //take it for sub2
        
        ans=(ans+(solve(i+1,arr,g1,gcd(g2,arr[i])))%MOD)%MOD;
        
        //not take it for nothing
        ans=(ans+(solve(i+1,arr,g1,g2))%MOD)%MOD;
        return dp[i][g1][g2]=ans%MOD;
 
    }
    int subsequencePairCount(vector<int>& nums) {
        // vector<int> a,b;
        dp.resize(nums.size()+1,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(0,nums,0,0);

    }
};