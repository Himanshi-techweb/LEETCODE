class Solution {
public:
    int check(int o,int c,vector<vector<int>>&adj,vector<int> &visit){
        if(o==c)return 0;
        if(visit[o])return INT_MAX;
        int mini=INT_MAX;
        visit[o]=1;
        for(int i=0;i<26;i++){
            if(adj[o][i]!=INT_MAX){
            //    visit[i]=1;
               long long x=check(i,c,adj,visit);
               if(x+adj[o][i]<INT_MAX){
                 mini=min(mini,adj[o][i]+(int)x);
               }
            //    visit[i]=0;
            }   
        }
        visit[o]=0;
        return mini;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // vector<vector<int>> adj(26,vector<int>(26,INT_MAX));
        // vector<vector<vector<int>>>(26,vector<vector<int>>(26,vector<int>(26,INT_MAX)));
        // for(auto i=0;i<original.size();i++){
        //     int o=original[i]-'a';int c=changed[i]-'a';
        //     adj[o][c]=min(adj[o][c],cost[i]);
        // }
        // int ans=0;
        // for(int i=0;i<source.size();i++){
        //     if(source[i]==target[i])continue;
        //     int o=source[i]-'a';int c=target[i]-'a';
        //     vector<int> visit(26,0);
        //     long long x=check(o,c,adj,visit);
        //     if(x>=INT_MAX)return -1;
        //     ans+=x;
        // }
        const long long INF = 1e18;

    // dist[i][j] = minimum cost to convert (char)(i+'a') -> (char)(j+'a')
    vector<vector<long long>> dist(26, vector<long long>(26, INF));

    // cost to convert same character is 0
    for (int i = 0; i < 26; i++) {
        dist[i][i] = 0;
    }

    // direct conversions
    for (int i = 0; i < original.size(); i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        dist[u][v] = min(dist[u][v], (long long)cost[i]);
    }

    // Floyd–Warshall
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // compute answer
    long long ans = 0;
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == target[i]) continue;

        int u = source[i] - 'a';
        int v = target[i] - 'a';

        if (dist[u][v] == INF) return -1;
        ans += dist[u][v];
    }
        return ans;
    }
};