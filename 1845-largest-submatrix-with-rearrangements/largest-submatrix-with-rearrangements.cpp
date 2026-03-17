class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();int n=matrix[0].size();
        //stack vertical height
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1 &&  i>0){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }

        //sort row by height of column
        for(int i=0;i<m;i++){
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
        }

        //begin to calculate area by increasing width 
        int maxarea=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxarea=max(maxarea,matrix[i][j]*(j+1));
            }
        }
        return maxarea;
    }
};