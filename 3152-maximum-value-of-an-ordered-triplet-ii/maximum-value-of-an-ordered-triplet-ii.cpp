class Solution {
public:
    // long long maximumTripletValue(vector<int>& nums) {
        
    // }
    long long maximumTripletValue(vector<int>& arr) {
        int n=arr.size();
      vector<int> left(n,0);
      left[0]=arr[0];
      vector<int > right(n,0);
      for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
      } 
      right[n-1]=arr[n-1];
      for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
      }long long ans=0;
      for(int i=1;i<n-1;i++){
        long long ans2=(long long)(left[i-1]-arr[i])*right[i+1];
        ans=max(ans,ans2);
      } 
      if(ans<0)return 0;
      return ans;
    }
};