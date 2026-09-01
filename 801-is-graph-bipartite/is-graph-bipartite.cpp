class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q; 
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    auto front=q.front();
                    q.pop();
                   for(auto it:graph[front]){
                    if(color[it]==-1){
                        color[it]=!color[front];
                        q.push(it);
                    }
                    else if(color[it]==color[front]){
                        return false;
                    }
                   }
                }
            }
        }
        return true;
    }
};