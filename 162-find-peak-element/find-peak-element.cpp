class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[n-1]>arr[n-2])return n-1;
        int l=1;
        int h=n-2;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])return mid;
            else if(arr[mid]<arr[mid+1]){
                ans=mid+1;
                l++;
            }
            else if(arr[mid]<arr[mid-1]){
                ans=mid-1;
                h--;
            }
        }
        return ans;
    }
};