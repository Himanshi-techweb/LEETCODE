class Solution {
public:
    int countSubarrays(vector<int>& arr) {

        int ans=0;
       for(int i=1;i<arr.size()-1;i++){
          int back=arr[i-1];
          int next=arr[i+1];
          if(arr[i]==2*(back+next))ans++;
       } 
       return ans;
    }
};