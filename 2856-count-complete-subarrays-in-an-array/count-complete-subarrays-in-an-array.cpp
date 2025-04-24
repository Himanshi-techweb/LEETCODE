class Solution {
public:
    int countCompleteSubarrays(vector<int>& arr) {
      set<int> q;
      for(auto x:arr){
       q.insert(x);
      }  
      unordered_map<int,int> check;
      int k=q.size();int ans=0;int l=0;int r=0;
      while( r<arr.size()){
         check[arr[r]]++;
         while(check.size()==k){
            ans+=(arr.size()-r);
            check[arr[l]]--;
            if(check[arr[l]]==0)check.erase(arr[l]);
            l++;
         }
         r++; 
      }
      return ans;
    }
};