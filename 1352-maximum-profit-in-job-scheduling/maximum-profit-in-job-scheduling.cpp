class Solution {
public:
    vector<int> ans;
    int solve(int i,vector<vector<int>> &arr,vector<int>&start){
        if(i>=start.size())return 0;
        if(ans[i]!=-1)return ans[i];
        int nextindex=lower_bound(start.begin(),start.end(),arr[i][1])-start.begin();
        int s=arr[i][0];int e=arr[i][1];int cost=arr[i][2];
        //take it
        int take=0;int nottake=0; 
        take+=cost+solve(nextindex,arr,start);
        //not take
        nottake+=solve(i+1,arr,start);
        return ans[i]=max({take,nottake,ans[i]});

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> arr;
        for(int i=0;i<startTime.size();i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        sort(startTime.begin(),startTime.end());
        ans.resize(startTime.size(),-1);
        //take this index if take it then 
        
        int maxi=solve(0,arr,startTime);
        
        return maxi;
        
    }
};