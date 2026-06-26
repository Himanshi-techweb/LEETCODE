class Solution {
public:
    //try for low  & high and then call for cut ok
    //
    vector<vector<int>> dp;
    int solve(int l,int h,vector<int> &cut){
        if(h-l<2)return 0;
        if(dp[l][h]!=INT_MAX)return dp[l][h];
        int result=INT_MAX;
        
        //try for each index to be first in it 
        for(int i=l+1;i<=h-1;i++){
            int cost=cut[h]-cut[l]+solve(l,i,cut)+solve(i,h,cut);
            result=min(result,cost);
        }
        return dp[l][h]=result;
    }
    int minCost(int n, vector<int>& cut) {
        // vector<bool> flag(n,false);
        cut.push_back(0);
        cut.push_back(n);
        sort(cut.begin(),cut.end());
        dp.resize(cut.size()+1,vector<int> (cut.size()+1,INT_MAX));
        return solve(0,cut.size()-1,cut);
    }
};