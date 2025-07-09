class Solution {
public:
    int maxProduct(vector<int>& arr) {
       int prefix=1;int suffix=1;
       int maxi=INT_MIN;
       for(int i=0;i<arr.size();i++){
         prefix=prefix*arr[i];
         maxi=max(prefix,maxi);
         if(prefix==0){
            prefix=1;
         }
       } 
       for(int i=arr.size()-1;i>=0;i--){
        suffix=suffix*arr[i];
        maxi=max(maxi,suffix);
        if(suffix==0)suffix=1;
       }
       return maxi;
    }
};