class Solution {
public:
    void dfs(int i,vector<vector<int>> &stone,vector<int> &visit){
       int r=stone[i][0];int c=stone[i][1];
       for(int j=0;j<stone.size();j++){
        if(!visit[j] && (stone[j][0]==r || stone[j][1]==c)){
            visit[j]=1;
            dfs(j,stone,visit);
        }
       }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       vector<int> visit(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
        if(!visit[i]){
            cnt++;
          dfs(i,stones,visit);
        }
       } 
       return n-cnt;
    }
};