class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
       //finding corner point in array
       int x=0;
       for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
           x=i;
           break;
        }
       } 
       //just next greater element
       int mini=INT_MAX;int mini_ix=n-1;
       for(int i=x+1;i<n;i++){
         if(arr[i]>arr[x] && arr[i]<mini){
            mini=arr[i];
            mini_ix=i;
         }
       }
       swap(arr[x],arr[mini_ix]);
       //sort just after x 
       sort(arr.begin()+x+1,arr.end());
       
    }
};