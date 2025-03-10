class Solution {
public:
    // int solve(int i,int j,int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    //     if(i>=m || j>=n)return INT_MAX;
    //     if(i==0 && j==0)return matrix;
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();
      vector<int> next=matrix[n-1];
      
      for(int i=n-2;i>=0;i--){
        vector<int> curr(n);
        for(int j=n-1;j>=0;j--){
        int left=(j>0)?next[j-1]:1e9;
        int below=next[j];
        int right=(j<n-1)?next[j+1]:1e9;
        curr[j]=matrix[i][j]+min(left,min(below,right));
        }
        next=curr;
      }
      return *min_element(next.begin(),next.end());
    }
};