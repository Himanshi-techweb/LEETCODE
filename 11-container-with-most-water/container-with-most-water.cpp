class Solution {
public:
    int maxArea(vector<int>&arr) {
      int n=arr.size();
      int l=0;
      int r=n-1;
      int leftmax=0;
      int rightmax=0;
      int ans=0;
      while(l<r){
        if(arr[l]<=arr[r]){
            ans=max(ans,arr[l]*(r-l));
            l++;
        }
        else{
            ans=max(ans,arr[r]*(r-l));
            r--;
        }
      }
      return ans;
    }
};