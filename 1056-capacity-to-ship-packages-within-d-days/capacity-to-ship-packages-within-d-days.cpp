class Solution {
public:
    bool solve(int mid,vector<int>&arr,int k){
        int cnt=0;int sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid)return false;
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else sum+=arr[i];
        }
        if(sum<=mid)cnt++;
        cout<<mid<<" "<<cnt<<endl;
        return cnt<=k;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int h=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(mid,weights,days)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};