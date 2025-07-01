class Solution {
public:
    int solve(vector<int> &arr,int k){
      int odd=0;int l=0;int r=0;int maxi=0;
      while(l<=r && r<arr.size()){
         if(arr[r]%2!=0)odd++;
         while(odd>k){
            if(arr[l]%2!=0)odd--;
            l++;
         }
         maxi+=(r-l+1);
         r++;
      } 
      return maxi; 
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
      return solve(arr,k)-solve(arr,k-1);
    }
};