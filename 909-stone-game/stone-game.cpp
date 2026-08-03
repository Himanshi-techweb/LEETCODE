class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int s,int e,vector<int>&arr,bool kon){
        if(s>e)return 0;
        int res=(kon==0)?INT_MIN:INT_MAX;
        if(dp[s][e][kon]!=-1)return dp[s][e][kon];
        if(!kon){
            int take_first=arr[s]+solve(s+1,e,arr,!kon);
            int take=arr[e]+solve(s,e-1,arr,!kon);
            res=max({res,take_first,take});
        }
        else{
            int take_first=solve(s+1,e,arr,!kon);
            int take=solve(s,e-1,arr,!kon);
            res=min({res,take_first,take});
            
        }
        return dp[s][e][kon]=res;
    }
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(),vector<vector<int>>(piles.size(),vector<int>(2,-1)));
        return solve(0,piles.size()-1,piles,0);
        
    }
};