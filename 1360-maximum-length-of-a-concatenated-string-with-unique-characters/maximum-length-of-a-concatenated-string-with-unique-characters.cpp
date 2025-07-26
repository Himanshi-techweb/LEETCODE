class Solution {
public:
    int solve(int i,vector<string> &arr,vector<int> &dp,vector<int> &check,int n){
        if(i>=n)return 0;
        //take string only when it does not contain check;
        // if(dp[i]!=-1)return dp[i];
        vector<int> check1(26,0);
        int take=0;bool flag=false;
        for(auto it:arr[i]){
            if(check[it-'a']>0 || check1[it-'a']>0){
                flag=true;
                break;
            }
            check1[it-'a']++;
        }
        if(!flag){
            for(auto it:arr[i]){
              check[it-'a']++;
            }
            take=arr[i].length()+solve(i+1,arr,dp,check,n);
            for(auto it:arr[i]){
              check[it-'a']--;
            }
        }
        int nottake=solve(i+1,arr,dp,check,n);
        return dp[i]=max(take,nottake);

    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        vector<int> check(26,0);
        return solve(0,arr,dp,check,n);
    }
};