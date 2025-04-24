class Solution {
public:
    int countCompleteSubarrays(vector<int>& arr) {
      set<int> check;
      for(auto x:arr){
       check.insert(x);
      }  
      int k=check.size();int ans=0;
      for(int i=0;i<arr.size();i++){
        set<int> q;
        for(int j=i;j<arr.size();j++){
            q.insert(arr[j]);
            if(q.size()==k)ans++;
        }
      }
      return ans;
    }
};