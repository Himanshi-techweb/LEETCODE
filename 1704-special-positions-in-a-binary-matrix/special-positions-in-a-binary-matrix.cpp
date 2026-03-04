class Solution {
public:
    int numSpecial(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<int> check_row(m,0);
        vector<int> check_col(n,0);
        for(int i=0;i<m;i++){
            //each row
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]==1)count++;
            }
            check_row[i]=count;
        }

        for(int i=0;i<n;i++){
            //each col
            int count=0;
            for(int j=0;j<m;j++){
                if(arr[j][i]==1)count++;
            }
            check_col[i]=count;
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    //both row col
                    if(check_row[i]==1 && check_col[j]==1)count++;
                }
            }
        }
        return count;

    }
};