class Solution {
public:
    const int MOD=1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector< vector< pair<int,long long> > >  adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]}); 
        }

        priority_queue< pair<long long,long long>, vector<pair<long long,long long>> ,greater<pair<long long,long long>>> q;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> way(n,0);
        dist[0]=0;way[0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto front=q.top();q.pop();
            long long u=front.second;long long wt=front.first;
            if(wt>dist[u])continue;
            for(auto it:adj[u]){
                long long v=it.first;long long time=it.second;
                if(dist[v]>dist[u]+time){
                    dist[v]=dist[u]+time;
                    way[v]=way[u]%MOD;
                    q.push({dist[v],v});
                }
                else if(dist[v]==dist[u]+time){
                    way[v]=(way[v]+way[u])%MOD;
                }
            }
        }
        return way[n-1]%MOD;
    }
};