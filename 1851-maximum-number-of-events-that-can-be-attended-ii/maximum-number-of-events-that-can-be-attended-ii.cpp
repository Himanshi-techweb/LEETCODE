class Solution {
public:
    //check number of current number of event taken if it equal to k then return 
    //take that index and nextindex will be taken from lower bound ok 
    //not take then nextindex i+1
    vector<vector<int>> dp;
    int solve(int i,int k,vector<vector<int>> &events){
        if(i>=events.size())return 0;
        if(k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        //take it then nextindex 
        int nextindex=upper_bound(events.begin(),events.end(),events[i][1],
            [](int x,const vector<int> &a){
                return x<a[0];
            }
        )-events.begin();
        int take=INT_MIN;
        if(k>0)take=events[i][2]+solve(nextindex,k-1,events);
        int nottake=solve(i+1,k,events);
        return dp[i][k]=max(take,nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        // vector<vector<int>> arr;
        dp.resize(events.size()+1,vector<int> (k+1,-1));
        sort(events.begin(),events.end());
        return solve(0,k,events);
    }
};