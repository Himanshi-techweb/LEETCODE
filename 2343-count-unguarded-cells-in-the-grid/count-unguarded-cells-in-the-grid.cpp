class Solution {
public:
    // vector<vector<int>> rc={{-1,0},{1,0},{0,-1},{0,1}};
    // void dfs(int i,int j,vector<vector<int>> &visit,int m,int n){
    //   visit[i][j]=1;
    // //   for(auto it:rc){
    // //     int nr=it[0]+i;int nc=it[1]+j;
    // //     if(nr>=0 && nr<m && nc>=0 && nc<n && visit[])
    // //   }
      
    // }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visit(m,vector<int> (n,0));
        //guards -1 ,walls -1,
        for(auto it:walls){
            visit[it[0]][it[1]]=-1;
        }
        for(auto it:guards){
            visit[it[0]][it[1]]=-1;
        }
        int r,c;
        for(auto it:guards){
            int i=it[0];int j=it[1];
            //right --> row same col +1 till n
            r=i;c=j;c++;
            while(c<n && visit[r][c]!=-1){
                visit[r][c]=1;
                c++;
            }

            //left --> row same col -1 till 0
            r=i;c=j;c--;
            while(c>=0 && visit[r][c]!=-1){
                visit[r][c]=1;
                c--;
            }

            //above --> col same row -1 till 0
            r=i;c=j;r--;
            while(r>=0 && visit[r][c]!=-1){
                visit[r][c]=1;
                r--;
            }

            //below --> col same row +1 till m
            r=i;c=j;r++;
            while(r<m && visit[r][c]!=-1){
                visit[r][c]=1;
                r++;
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(visit[i][j]==0)cnt++;
                }
        }
        return cnt;
    }
};