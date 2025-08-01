class Solution {
public:
    int solve(vector<int> &arr,int k){
       unordered_map<int,int> check;
       int l=0;
       int r=0;
       int cnt=0;
       while(l<=r && r<arr.size()){
          check[arr[r]]++;
          while(check.size()>k){
            check[arr[l]]--;
            if(check[arr[l]]==0)check.erase(arr[l]);
            l++;
          }
          cnt+=(r-l+1);
          r++;
       } 
       return cnt;
    }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
      return solve(arr,k)-solve(arr,k-1);
    }
};