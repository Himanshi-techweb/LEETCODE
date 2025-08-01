class Solution {
public:
    int solve(vector<int> &arr,int k){
        if(k<0)return 0;
        int l=0;int r=0;int cnt=0;int freq=0;
        while(l<=r && r<arr.size()){
            if(arr[r]%2!=0)freq++;
            while(freq>k){
                if(arr[l]%2!=0){
                    freq--;
                }
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        return solve(arr,k)-solve(arr,k-1);
    }
};