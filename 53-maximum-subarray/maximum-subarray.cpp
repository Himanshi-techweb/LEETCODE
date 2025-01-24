class Solution {
public:
    int maxSubArray(vector<int>& arr) {
      if(arr.size()==1)return arr[0];
      int ans=INT_MIN;
      int sum=0;
      for(auto x:arr){
        sum+=x;
        ans=max(ans,sum);
        if(sum<0)sum=0;
      }
      return ans;
    }
};