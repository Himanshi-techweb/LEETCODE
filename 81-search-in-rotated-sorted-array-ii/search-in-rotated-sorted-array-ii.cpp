class Solution {
public:
    bool search(vector<int>& arr, int tar) {
       int low=0;
      int high=arr.size()-1;  
      int ans=-1;
      while (low <= high) {
            int mid = low + (high-low)/2;

            if (arr[mid] == tar) return true;
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                low++;
                high--;
                continue;
                
            }
            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                if (tar >= arr[low] && tar < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (tar > arr[mid] && tar <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false; 
    }
};