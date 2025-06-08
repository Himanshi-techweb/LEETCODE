class Solution {
public:
    int search(vector<int>& arr, int tar) {
      int low=0;
      int high=arr.size()-1;  
      int ans=-1;
      while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==tar)ans=mid;
        if(arr[low]<=arr[mid]){//sorted left
           if(tar >= arr[low] && tar<arr[mid]){
              high=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        
        else {//sorted right
           if(tar>arr[mid] && tar<=arr[high]){
              low=mid+1;
           }
           else{
            high=mid-1;
           }
        }
        
      }return ans; 
    }
};