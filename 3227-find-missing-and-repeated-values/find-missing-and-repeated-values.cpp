class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      int n=grid.size();
      vector<int> arr((n*n) +1,0);
      vector<int> ans(2,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[grid[i][j]]>1){
               ans.push_back(arr[grid[i][j]]);
               break;
            }
            arr[grid[i][j]]++;     
        }
      }
      for(int i=0;i<arr.size();i++){
        if(i!=0 && arr[i]==0){
           ans[1]=i;
        } 
        if(arr[i]>1){
            ans[0]=i;
        }
      }
      return ans; 
    }
};