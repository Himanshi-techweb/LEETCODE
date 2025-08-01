class Solution {
public:
    void sortColors(vector<int>& arr) {
      int low=0;int mid=0;int high=arr.size()-1; 
      while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
      } 
    }
};