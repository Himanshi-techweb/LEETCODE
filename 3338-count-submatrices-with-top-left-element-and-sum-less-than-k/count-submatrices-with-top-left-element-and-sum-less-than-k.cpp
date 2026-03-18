class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> prefixsum(m,vector<int>(n,0));
    //    vector<int> prefixcol(n,0);
    //    vector<int> suffixsum(m,0);
        prefixsum[0][0]=grid[0][0];
        // for(int j=1;j<n;j++){
        //     // prefixsum[i]=grid[i]+prefix[i-1];
        //     prefixsum[0][j]=grid[0][j];
        // } 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    prefixsum[0][j]=grid[0][j];
                }
                else
                prefixsum[i][j]=grid[i][j]+prefixsum[i-1][j];
            }
        }
        int count=0;
        //iterate through each row select column from 0 to n
        for(int i=0;i<m;i++){
            int sum=0;
            //iterate through column
            for(int j=0;j<n;j++){
               sum=sum+prefixsum[i][j];
               if(sum<=k)count++;
            }
        }

        // through 1 
        return count;
    }
};