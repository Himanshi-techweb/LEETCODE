class Solution {
public:
    bool search(vector<int>& arr, int target) {
       int low=0;int high=arr.size()-1;
        while(low<=high){
        int  mid=low+(high-low)/2;
        if(arr[mid]==target)return true;
        while(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;high--;
            if(low>=arr.size() || high<0)return false;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target  && target<arr[mid])high=mid-1;
            else low=mid+1;
        }
        else{
            if(arr[mid]<target && target<=arr[high])low=mid+1;
            else high=mid-1;
        }
       }  
       return false;  
    }
};