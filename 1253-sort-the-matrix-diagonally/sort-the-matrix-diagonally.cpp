class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& matrix) {
        vector<int> arr;
        //try leftmost column
        int m=matrix.size();int n=matrix[0].size();
        int j=0;
        for(int i=m-1;i>=0;i--){
            //
            int r=i;int c=j;
            arr={};
            while(r<m && c<n){
                arr.push_back(matrix[r][c]);
                r++;c++;
            }

            sort(arr.begin(),arr.end());
            int k=0;
            r=i;c=j;
            while(r<m && c<n && k<arr.size()){
                matrix[r][c]=arr[k];
                r++;c++;k++;
            }
        }
        arr={};
        //topmost row
        int i=0;
        for(int j=1;j<n;j++){
            int r=i;int c=j;
            arr={};
            while(r<m && c<n){
                arr.push_back(matrix[r][c]);
                r++;c++;
            }
            sort(arr.begin(),arr.end());
            int k=0;
            r=i;c=j;
            while(r<m && c<n && k<arr.size()){
                matrix[r][c]=arr[k];
                r++;c++;k++;
            }
        }
        return matrix;
    }
};