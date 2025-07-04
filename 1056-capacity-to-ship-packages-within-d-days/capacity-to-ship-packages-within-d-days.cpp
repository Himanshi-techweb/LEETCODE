class Solution {
public:
    bool check(int mid,vector<int> &arr,int days){
       int cnt=0;int sum=0;
       for(auto it:arr){
         if(it>mid)return false;
         if(sum+it<=mid){
            sum=sum+it;
         }
         else{
            cnt++;
            sum=it;
         }
       }
       cnt++;
       return cnt<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
      int low=*min(arr.begin(),arr.end());
      int high=accumulate(arr.begin(),arr.end(),0);
      int capacity=0;
      while(low<=high){
        int mid=low+(high-low)/2;
        if(check(mid,arr,days)){
            capacity=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      } 
      return capacity; 
    }
};