class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
       for(int i=0;i<matrix[0].size();i++){
        for(int j=0;j<m/2;j++){
            swap(matrix[j][i],matrix[m-j-1][i]);
        }
       } 

       for(int i=0;i<m;i++){
         for(int j=i+1;j<m;j++){
            swap(matrix[i][j],matrix[j][i]);
         }
       }
    }
};