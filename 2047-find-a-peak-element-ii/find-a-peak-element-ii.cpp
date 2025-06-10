class Solution {
public:
    int maxelement(int mid,vector<vector<int>>&mat ){
        int m=mat.size();
        int maxi=0;
        int ix=0;
        for(int i=0;i<m;i++){
           if(mat[i][mid]>maxi){
            maxi=mat[i][mid];
            ix=i;
           }
        }
        return ix;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int m=mat.size();int n=mat[0].size();
      int low=0;int high=n-1;
      while(low<=high){
        int mid=(low+high)>>1;
        int row=maxelement(mid,mat);
        int left=(mid-1>=0)?mat[row][mid-1]:-1;
        int right=(mid+1<n)?mat[row][mid+1]:-1;
        if(mat[row][mid]>left && mat[row][mid]>right)return {row,mid};
        else if((mat[row][mid]<left))high=mid-1;
        else low=mid+1;
      } 
      return {-1,-1};
    }
};