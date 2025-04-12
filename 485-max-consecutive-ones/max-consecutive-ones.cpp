class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
      int ans=INT_MIN;int l=0;int r=0;
      while(l<=r  && r< arr.size()){
        if(arr[r]==0){
            ans=max(ans,r-l);
            r=r+1;l=r;
        }
        else{
            ans=max(ans,r-l+1);
           r++;
        }
      } 
      return ans; 
    }
};