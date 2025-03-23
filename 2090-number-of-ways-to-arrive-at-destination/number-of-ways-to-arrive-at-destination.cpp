class Solution {
public:
    int countPaths(int n, vector<vector<int>>& road) {
       vector<long long> dist(n,LLONG_MAX);
       vector<long long> way(n,0);
       long long mod=(1e9)  + 7;
       priority_queue<pair<long ,long>,vector<pair<long,long>>,greater<pair<long ,long>>> q;//{length,node}
       vector<vector<pair<long,long>>>arr(n);
       for(int i=0;i<road.size();i++){
        arr[road[i][0]].push_back({road[i][1],road[i][2]});
        arr[road[i][1]].push_back({road[i][0],road[i][2]});
       }
       dist[0]=0;
       way[0]=1;
       q.push({0,0});
       while(!q.empty()){
        long long length=q.top().first;
        long long node=q.top().second;
        q.pop();
        for(auto it:arr[node]){
            if(length+it.second<dist[it.first]){
                dist[it.first]=length+it.second;
                way[it.first]=way[node];
                q.push({length+it.second,it.first});
            }
            else if(length+it.second==dist[it.first]){
                way[it.first]=(way[node]+way[it.first])%mod;
            }
        }
       }return way[n-1]%mod;
    }
};