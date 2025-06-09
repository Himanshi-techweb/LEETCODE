class Solution {
public:
    long long check(int x,int h,vector<int> &arr){
        long long q=0;
      for(auto i:arr){
        
         if(i%x==0){
            q+=i/x;
         }
         else{
            q+=(i/x)+1;
         }
        //  y+=q;
      }
      return q;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
      int maxi=*max_element(arr.begin(),arr.end());  
      int low=1;
      int high=maxi;int ans=1;
      while(low<=high){
        long long mid=low + (high-low)/2;
        // if(check(mid,h,arr)==h){
        //     ans=mid;
        //     high=mid-1;
        // }
        if(check(mid,h,arr)<=h){ 
             ans=mid;
           high=mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return ans;
    }
};