class Solution {
public:
    bool check(int mid,vector<int> &arr,int threshold){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<mid)cnt++;
            else if(arr[i]%mid==0){
                cnt+=(arr[i]/mid);
            }
            else if(arr[i]%mid!=0){
                cnt+=(arr[i]/mid);
                cnt++;
            }
        }
        return cnt<=threshold;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
       int low=1;
       int high=*max_element(arr.begin(),arr.end());
       int ans=0;
       while(low<=high){
          int mid=low+(high-low)/2;
          if(check(mid,arr,threshold)){
            ans=mid;
            high=mid-1;
          }
          else low=mid+1;
       }
       return ans; 
    }
};