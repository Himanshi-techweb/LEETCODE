class Solution {
public:
    // int check(vector<vector<pair<int,int>>> &in,vector<vector<pair<int,int>>> &out,int n,int i,vector<int>&visit,vector<int>&dp){
    //     if(i>=n)return INT_MAX;
    //     if(i==n-1)return 0;
    //     if(visit[i])return INT_MAX;
    //     if(dp[i]!=-1)return dp[i];
    //     visit[i]=1;
    //     int mini1=INT_MAX;
    //     int mini2=INT_MAX;
    //     //no reverse it
    //     for(auto it:in[i]){
    //         //    visit[it.first]=1;
    //            long long check1=check(in,out,n,it.first,visit,dp);
    //            if(check1+it.second<INT_MAX){
    //               mini1=min(mini1,it.second+(int)check1);
    //            }
    //         //    visit[it.first]=0;
    //         // }    
    //     }


    //     //reverse it
    //     for(auto it:out[i]){
    //         // if(!visit[it.first]){
    //         // visit[it.first]=1;
    //         long long check2=check(in,out,n,it.first,visit,dp);
    //         if(check2+2*it.second<INT_MAX){
    //             mini2=min(mini2,2*it.second+(int)check2);
    //         }
    //         // visit[it.first]=0;
    //         // }
    //     }
    //     visit[i]=0;
    //     return dp[i]= min(mini1,mini2);
    // }

    // int minCost(int n, vector<vector<int>>& edges) {
    //    vector<vector<pair<int,int>>> in(n+1);
    //    vector<vector<pair<int,int>>> out(n+1);
    // //    vector<vector<int>> arr(n,vector<int>(n,INT_MAX));
    //    vector<int> visit(n,0);
    //    vector<int> dp(n,-1);
    // // visit[0]=-1;
    //    for(auto it:edges){
    //     int u=it[0];int v=it[1];int wt=it[2];
    //     in[u].push_back({v,wt});
    //     out[v].push_back({u,wt});
    //    } 
    //    int x=check(in,out,n,0,dp);
    //    return x==INT_MAX?-1:x;
    // }
    int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(n);

    for(auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});        // normal
        adj[v].push_back({u, 2*w});      // reversed
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> dist(n, INT_MAX);

    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if(cost > dist[u]) continue;
        if(u == n-1) return cost;

        for(auto [v, w] : adj[u]) {
            if(dist[v] > cost + w) {
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }

    return -1;
}

};