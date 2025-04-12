class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
      int ans=INT_MIN;int l=0;int r=0;int zero=0;
      while(r<arr.size()){
        if(arr[r]==0)zero++;
        while(zero>k){
            if(arr[l]==0)zero--;
            l++;
        }
        ans=max(r-l+1,ans);
        r++;
      } 
      return ans; 
    }
};