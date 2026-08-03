class Solution {
public:
    //kon 0 alice kon 1 bob
    int n;
    // unordered_map<int,unordered_map<bool,int>> dp;
    vector<long long> dp;
    long long solve(int i,vector<int> &arr){
        if(i>=n)return 0;
        //alice -bob
        //take 1
        // if(dp.find(i)!=dp.end() && dp[i].find(kon) !=dp[i].end())return dp[i][kon];
        if(dp[i]!=LLONG_MIN)return dp[i];
        long long take2=INT_MIN;
        long long take3=INT_MIN;
        
            long long take1=(arr[i])-solve(i+1,arr); 
            if(i+1<n)take2=((long long)arr[i]+arr[i+1])-solve(i+2,arr);
            if(i+2<n)take3=((long long)arr[i]+arr[i+1]+arr[i+2])-solve(i+3,arr);
            return dp[i]=max({take1,take2,take3});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n+1,LLONG_MIN);
        dp[n]=0;
        // long long ans=solve(0,stoneValue);
        for(int i=n-1;i>=0;i--){
            long long take2=LLONG_MIN;
            long long take3=LLONG_MIN;
        
            long long take1=(stoneValue[i])-dp[i+1]; 
            if(i+1<n)take2=((long long)stoneValue[i]+stoneValue[i+1])-dp[i+2];
            if(i+2<n)take3=((long long)stoneValue[i]+stoneValue[i+1]+stoneValue[i+2])-dp[i+3];
            dp[i]=max({dp[i],take1,take2,take3});
        }

        
        if(dp[0]>0)return "Alice";
        else if(dp[0]<0)return "Bob";
        return "Tie";
    }
};