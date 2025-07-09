class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int ix=-1;
       for(int i=arr.size()-2;i>=0;i--){
         if(arr[i]<arr[i+1]){
            ix=i;break;
         }
       }
       if(ix==-1){
        reverse(arr.begin(),arr.end());
        
       }
       else{
        for(int j=arr.size()-1;j>ix;j--){
            if(arr[j]>arr[ix]){
                swap(arr[ix],arr[j]);
                break;
            }
            
        }
        reverse(arr.begin()+ix+1,arr.end());
       }
    }
};