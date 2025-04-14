class Solution {
public:
    vector<vector<int>> generate(int row) {
        vector<vector<int>> ans;vector<int> curr;
      for(int i=0;i<row;i++){
         vector<int> arr(i+1,1);
         for(int j=1;j<i;j++){
           arr[j]=curr[j-1]+curr[j]; 
         }
         curr=arr;
         ans.push_back(curr);
      }  
      return ans;
    }
};