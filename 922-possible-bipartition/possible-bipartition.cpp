class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       vector<vector<int>> adj(n+1);
       for(auto it:dislikes){
         adj[it[0]].push_back(it[1]);
         adj[it[1]].push_back(it[0]);
       }
       vector<int> visit(n+1,0);
       vector<int> color(n+1,-1);
       for(int i=1;i<=n;i++){
          if(color[i]==-1){
            queue<int> q;
            q.push(i);visit[i]=1;color[i]=0;
            while(!q.empty()){
                auto front=q.front();q.pop();
                for(auto it:adj[front]){
                    if(color[it]==color[front])return false;
                    else{
                        if(color[it]==-1){
                            color[it]=!color[front];
                            q.push(it);
                        }
                    }
                }
            }
          } 
       }
       return true;
    }
};