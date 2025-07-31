class Solution {
public:
    bool check(vector<int> &arr,int mid,int h){
        long long cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<mid)cnt++;
            else if(arr[i]%mid==0)cnt+=(arr[i]/mid);
            else if(arr[i]%mid!=0){
                cnt+=(arr[i]/mid);
                cnt++;
            }
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};