class Solution {
public:
    bool check(int mid,int thre,vector<int> &arr){
        long long ans=0;
        for(auto x:arr){
            ans+=ceil ((double)x/(double)mid);
        }
        return ans<=thre;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int ans=0;
      int low=1;
      int high=*max_element(arr.begin(),arr.end());
      while(low<=high){
        int mid=low + (high-low)/2;
        if(check(mid,threshold,arr)){
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