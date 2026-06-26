class Solution {
public:
    int s,f;
    vector<vector<int>> dp;
    const int MOD=1e9 + 7;
    int solve(int i,vector<int> &arr,int fuel){
        if(i==arr.size())return 0;
        if(fuel<0)return 0;
        else if(fuel==0){
            if(i==f)return 1;
            return 0;
        }
        if(dp[i][fuel]!=-1)return dp[i][fuel];
        int way=0;
         if(i==f)way+=1;
        //reach finish location increase count and then move to next location 
        for(int j=0;j<arr.size();j++){
            if(j==i)continue;
            //next location j
            //consume fuel
            //consider it ok
            // if(fuel-abs(arr[i]-arr[j])>=0 && j==f)way=way+1;
            if(fuel-(abs(arr[i]-arr[j]))>=0)way=(way+solve(j,arr,fuel-abs(arr[i]-arr[j])))%MOD;
        }
        return dp[i][fuel]=way%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        f=finish;
        dp.resize(locations.size()+1,vector<int>(fuel+1,-1));
        return solve(start,locations,fuel);
    }
};