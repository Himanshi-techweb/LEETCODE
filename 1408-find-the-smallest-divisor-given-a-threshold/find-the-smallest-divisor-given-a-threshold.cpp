class Solution {
public:
    int solve(int mid,int t,vector<int>&arr){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%mid==0)cnt+=(arr[i]/mid);
            else cnt+=((arr[i]/mid)+1);
        }
        return cnt<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int ans=0;
        int h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(mid,threshold,nums)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};