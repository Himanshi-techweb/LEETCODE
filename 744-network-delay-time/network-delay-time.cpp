class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for(auto it:times){
             adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            auto x=q.top();q.pop();
            int wt=x.first;int u=x.second;
            for(auto it:adj[u]){
                int v=it[0];int time=it[1];
                if(dist[v]>dist[u]+time){
                    dist[v]=dist[u]+time;
                    q.push({dist[v],v});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX)return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};