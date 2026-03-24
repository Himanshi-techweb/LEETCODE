class Solution {
public:
    const int MOD=12345;
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> suffix(n,vector<long long>(m,1));
        vector<vector<long long>> prefix(n,vector<long long>(m,1));
        vector<long long> rowprod(n,1);
        vector<vector<int>> ans(n,vector<int>(m,0));
        //calculate prefix and suffix ok
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
               prefix[i][j]=(prefix[i][j-1]*grid[i][j-1])%MOD;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=m-2;j>=0;j--){
                suffix[i][j]=(suffix[i][j+1]*grid[i][j+1])%MOD;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowprod[i]=(rowprod[i]*grid[i][j])%MOD;
            }
        }
         
        vector<long long> prefixrow(n,1);
        vector<long long> suffixrow(n,1);
        for(int i=1;i<n;i++){
            prefixrow[i]=(prefixrow[i-1]*rowprod[i-1])%MOD;
        }
        
        for(int i=n-2;i>=0;i--){
            suffixrow[i]=(suffixrow[i+1]*rowprod[i+1])%MOD;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               long long currrow=(suffix[i][j]*prefix[i][j])%MOD;
               long long otherrow=(prefixrow[i]*suffixrow[i])%MOD;
               ans[i][j]=(currrow*otherrow)%MOD;
            }
        }

        return ans;


    }
};