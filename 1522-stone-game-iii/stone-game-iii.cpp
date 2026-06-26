class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int person,int i,vector<int> &piles){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int result;//person=1:Alice
        result=piles[i]-solve(!person,i+1,piles);
        if(i+1<n)result=max(result,piles[i]+piles[i+1]-solve(!person,i+2,piles));
        if(i+2<n)result=max(result,piles[i]+piles[i+1]+piles[i+2]-solve(!person,i+3,piles));
        
        return dp[i]=result;
    }
   
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.resize(n+1,-1);
        int res=solve(1,0,stoneValue);
        cout<<res<<endl;
        if(res>0)return "Alice";
        else if(res<0)return "Bob";
        else return "Tie";
    }
};