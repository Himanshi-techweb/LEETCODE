class Solution {
public:
    int search(vector<int>& arr, int tar) {
      int low=0;int high=arr.size()-1; 
      while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==tar)return mid;
        if(arr[mid]<arr[high]){
            if(tar<=arr[high] && tar>arr[mid])low=mid+1;
            else{
                high=mid-1;
            }
        }
        else{
            if(arr[low]<=tar && tar<arr[mid])high=mid-1;
            else low=mid+1;
        }
      } 
      return -1;
    }
};