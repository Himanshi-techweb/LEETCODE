class Solution {
public:
    bool solve(int i,vector<int> &arr,vector<int> &dp){
        if(i>=arr.size()-1)return dp[i]=true;
        if(arr[i]==0)return false;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=arr[i];j++){
           if(i+j<=arr.size()-1){
               if(solve(i+j,arr,dp)) return dp[i]= true;
           } 
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& arr) {
        int maxi=*max_element(arr.begin(),arr.end());
       vector<int> dp(arr.size(),-1);
       if(arr.size()==1)return true;
       if(arr[0]==0)return false;
       return solve(0,arr,dp); 
    }
};