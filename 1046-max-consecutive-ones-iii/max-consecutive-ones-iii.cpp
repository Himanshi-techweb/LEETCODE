class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
      int l=0;int r=0;
      int n=arr.size();
      int cnt_0=0;int maxcnt=0;
      while(l<=r && r<n){
        if(arr[r]==0){
           cnt_0++;
        }
        while(cnt_0>k){
            if(arr[l]==0)cnt_0--;
            l++;
        }
        maxcnt=max(maxcnt,r-l+1);
        r++;
      }  
      return maxcnt;
    }
};