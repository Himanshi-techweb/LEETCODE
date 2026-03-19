class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();int n=grid[0].size();
        // X Y
        vector<vector<vector<int>>> count(m,vector<vector<int>>(n,vector<int>(2,0)));
        if(grid[0][0]=='X')count[0][0]={1,0};
        
        else if(grid[0][0]=='Y')count[0][0]={0,1};
        
        for(int j=1;j<n;j++){
            // vector<int> x;
            count[0][j][0]=(grid[0][j]=='X')?1:0;
            count[0][j][1]=(grid[0][j]=='Y')?1:0;
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                    count[i][j]=count[i-1][j];
                    continue;
                }
                // vector<int> x;
                count[i][j][0]=(grid[i][j]=='X')?count[i-1][j][0]+1:count[i-1][j][0];
                count[i][j][1]=(grid[i][j]=='Y')?count[i-1][j][1]+1:count[i-1][j][1];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int x=0;int y=0;
            for(int j=0;j<n;j++){
                x+=count[i][j][0];y+=count[i][j][1];
                if(x>0 && x==y)ans++;
            }
        }
        
        return ans;
    }
};