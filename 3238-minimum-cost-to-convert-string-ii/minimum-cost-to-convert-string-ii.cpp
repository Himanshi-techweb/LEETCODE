class Solution {
public:
typedef long long ll;
unordered_map<string,unordered_map<string,int>> adj;
const ll INF=1e18;
vector<ll> dp;
string src;string tar;
set<int> st;
long long dijkstra(
    string &src,
    string &dest,
    unordered_map<string, unordered_map<string,int>> &adj
){
    priority_queue<
        pair<long long,string>,
        vector<pair<long long,string>>,
        greater<pair<long long,string>>
    > pq;

    unordered_map<string,long long> dist;

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();

        if(u == dest) return dist[dest];
        if(cost > dist[u]) continue;

        if(!adj.count(u)) continue;

        for(auto &it : adj[u]){
            string v = it.first;
            int w = it.second;

            if(!dist.count(v) || dist[v] > cost + w){
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }
    return (!dist.count(dest)? INF:dist[dest]);
}

    long long solve(int i){
        if(i>=src.size())return 0;
        ll mini=INF;
        if(dp[i]!=-1)return dp[i];
        if(src[i]==tar[i]){
            mini=solve(i+1);
        }
        for(auto it:st){
            if(it+i>src.size() || it+i>tar.size())break;
            string srcstr=src.substr(i,it);
            string tarstr=tar.substr(i,it);
            if(!adj.count(srcstr))continue;
            ll minpathcost=INF;
            minpathcost=dijkstra(srcstr,tarstr,adj);
            if(minpathcost==INF)continue;
            mini=min(mini,minpathcost+solve(i+it));
        }
        return dp[i]=mini;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        for(int i=0;i<original.size();i++){
                adj[original[i]][changed[i]]=min((ll)cost[i],adj[original[i]][changed[i]]==0?INF:adj[original[i]][changed[i]]);
                // adj[original[i]][changed[i]]=cost[i]; 
        }
        for(int i=0;i<original.size();i++){
            st.insert(original[i].size());
        }
        src=source;tar=target;
        // vector<ll> dp(source.size(),-1);
        dp.resize(source.size()+1,-1);
        long long ans= solve(0);
        if(ans==INF)return -1;
        return ans;
        
    }
};