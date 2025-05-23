class Solution {
public:
    // int solve(vector<int> & arr,int n){
    //     int diff=0;
    //     size_t ans=0;
    //    for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //        size_t check=0;
    //        diff=arr[j]-arr[i];
    //        int temp=arr[i]-diff;
    //        int k=i;
    //        while(k>=0 ){
    //          auto it = std::find(arr.begin(), arr.begin() +k, temp);
    //          if(it != arr.begin() + k){
    //            check++;
    //            k=it-arr.begin();
    //            temp=temp-diff;
    //          }
    //          else{
    //             break;
    //          }
    //        }
    //        ans=max(ans,check);
    //     }
    //    }
    //    return ans;
    // // }                                                                                           
    // int solveMem(int i,vector<int> & arr,int diff,vector<unordered_map<int,int>> &dp){
    //     if(i<0)return 0;
    //     if(dp[i].count(diff))return dp[i][diff];
    //     int ans=0;

    //     for(int k=i-1;k>=0;k--){
    //         if(arr[i]-arr[k]==diff){
    //             ans=max(ans,1+solve(k,arr,diff,dp));
    //         }
    //     }
    //    return dp[i][diff]=ans;
    // }                                                                                           
    int longestArithSeqLength(vector<int>& nums) {
      int n=nums.size();
      if(n<=2)return n;
      int ans=0;
    // //   unordered_map<int,int> dp[n+1];
    vector<unordered_map<int,int>> dp(n+1);
    //   for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         ans=max(ans,2+solve(i,nums,nums[j]-nums[i],dp));
    //     }
    //   } 
    //   return ans;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=nums[i]-nums[j];
            int count=1;
            if(dp[j].count(diff)){
                count=dp[j][diff];
            }
            dp[i][diff]=1+count;
            ans=max(ans,dp[i][diff]);
        }
    }return ans;
    }
};