class Solution {
public:
    const int MOD=1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            int x=it[0];int y=it[1];int wt=it[2];
            adj[x].push_back({y,wt});
            adj[y].push_back({x,wt});
        }
        using t=pair<long long,int>;
        priority_queue<t,vector<t>,greater<t>> q;
        q.push({0,0});
        vector<long long> dis(n,LLONG_MAX);
        dis[0]=0;
        vector<long long> count(n,0);
        count[0]=1;
        while(!q.empty()){
            auto node=q.top().second;
            auto cnt=q.top().first;
            q.pop();
            if(cnt>dis[node])continue;
            for(auto it:adj[node]){
                int next=it.first;int wt=it.second;
                long long x=dis[node]+wt;
                if(x<dis[next]){
                    dis[next]=x;
                    count[next]=count[node]%MOD;
                    q.push({dis[next],next});
                }
                else if(x==dis[next]){
                    count[next]=(count[next]+count[node])%MOD;
                    // q.push({dis[next],next});
                }
            }
        }
        return count[n-1];

    }
};