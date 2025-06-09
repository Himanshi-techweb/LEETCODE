class Solution {
public:
    bool check(int mid ,int k,vector<int> &arr){
        int sum=0;int cnt=1;
        for(auto x:arr){
            if(sum+x>mid){
                cnt++;
                sum=x;
            }
            else{
                sum+=x;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& arr, int k) {
       int low=*max_element(arr.begin(),arr.end());
       int high=accumulate(arr.begin(),arr.end(),0);
       int ans=0;
       while(low<=high){
        int mid=low + (high-low)/2;
        if(check(mid,k,arr)){
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