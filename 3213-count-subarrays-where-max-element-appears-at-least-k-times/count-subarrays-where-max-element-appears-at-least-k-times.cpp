class Solution {
public:
    long long countSubarrays(vector<int>& arr, int tar) {
        int maxi=arr[0];long long ans=0;
      for(auto x:arr){
        maxi=max(maxi,x);
      }int j=0;int k=0;
      int count=0;
      while(k<arr.size()){
        if(arr[k]==maxi){
            count++;
        }
        while(count>=tar){
            ans+=(arr.size()-k);
            if(arr[j]==maxi)count--;
            j++;
        }
         k++;
      }
      return ans;  
    }
};