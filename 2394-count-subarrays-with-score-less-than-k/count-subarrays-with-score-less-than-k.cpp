class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long k) {
        long long ans=0;int l=0;int r=0;long long sum=0;
        while(r<arr.size()){
            int x=arr[r];
            sum+=x;
            while(l<r && sum*(r-l+1)>=k){
                sum-=arr[l];
                l++;
            }
            if(sum*(r-l+1)<k){
                ans+=(r-l+1);
            }
            
            r++;
        }
        return ans;
    }
};