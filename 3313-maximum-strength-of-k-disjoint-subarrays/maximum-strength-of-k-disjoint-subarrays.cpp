class Solution {
public:
    const long long mini=-1e16;
    vector<vector<vector<long long>>> dp;
    long long solve(int i,int k,vector<int>&arr,bool startnew){
        if(k==0)return 0;
        if(i==arr.size())return mini;
        if(dp[i][k][startnew]!=-mini)return dp[i][k][startnew];
        //take it
        long long nottake= mini;
        if(startnew){
            nottake=solve(i+1,k,arr,true);
        }
        //take n continue
        long long take=1LL*arr[i]*((k%2==0)?-k:k)+solve(i+1,k,arr,false);

        take=max(take,1LL*arr[i]*((k%2==0)?-k:k)+solve(i+1,k-1,arr,true));



        
        return dp[i][k][startnew]=max(take,nottake);
    }
    long long maximumStrength(vector<int>& nums, int k) {
        dp.resize(nums.size()+1,vector<vector<long long>>(k+1,vector<long long> (2,-mini)));
        // vector<int> arr(nums.size()+1,0);
        // for(int i=0;i<s.size();i++){
        //     arr[i+1]=arr[i]+nums[i];
        // }
        return solve(0,k,nums,true);
    }
};