class Solution {
public:
    bool calc(int mid,int m,int k,vector<int> &arr){
        int x=arr.size();
        long long cnt=0;int i=0;long long ans=0;
        for(int j=0;j<arr.size();j++){
          if(arr[j]<=mid){
            cnt++;
          }
          else{
            ans+=(cnt/k);
            cnt=0;
          }
        }
        if(cnt!=0)ans+=(cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        if(n<(long long)m*k)return -1;long long ans=-1;
        int low=1;int high=*max_element(arr.begin(),arr.end());
        while(low<=high){
            long long  mid =low + (high-low)/2;
            if(calc(mid,m,k,arr)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};