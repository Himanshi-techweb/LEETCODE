class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n=arr.size();int sq=(n*n)+1;
        vector<int> ans(2,0);
      vector<int> check(sq,0); 
      for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
           check[arr[i][j]]+=1;
           if(check[arr[i][j]]==2)ans[0]=arr[i][j];
        }
      } 
      for(int i=1;i<check.size();i++){
        if(check[i]==0 )ans[1]=i;
      } 
      return ans;
    }
};