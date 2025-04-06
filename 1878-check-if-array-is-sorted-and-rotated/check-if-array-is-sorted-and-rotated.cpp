class Solution {
public:
    bool check(vector<int>& arr) {
        int n=arr.size();int curr=arr[0];int k=0;
        int i=1;
       for(i=1;i<n;){
          if(arr[i]>=curr){
            curr=arr[i];
           i++;
          }
          else{
            k=i;
            break;
          }
       } if(i==n)return true;
       vector<int> result;
       for(int j=k;k<n;k++){
        result.push_back(arr[k]);
       }
       for(int i=0;i<k;i++){
        result.push_back(arr[i]);
       }
       for(int i=0;i<n-1;i++){
        if(result[i+1]<result[i])return false;
       }
       return true;
    }
};