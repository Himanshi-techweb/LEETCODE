class Solution {
public:
    bool check(int mid,int days,vector<int> &arr){
        int i=0;int j=0;int day=1;
        for(auto x: arr){
          if(i+x>mid){
            day++;
            i=x;
          }
          else{
            i+=x;
          }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int low=*max_element(arr.begin(),arr.end());int ans=0;
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low + (high-low)/2;
            if(check(mid,days,arr)){
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