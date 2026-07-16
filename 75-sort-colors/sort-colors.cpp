class Solution {
public:
    void sortColors(vector<int>& arr) {
       int l=-1;
       int r=arr.size()-1;
       int k=0;
       while(k<=r){
         if(arr[k]==2){
            swap(arr[r],arr[k]);
            r--;
         }
         else if(arr[k]==0){
            swap(arr[++l],arr[k]);
           
            k++;
         }
         else{
            k++;
         }

       } 
       
    }
};