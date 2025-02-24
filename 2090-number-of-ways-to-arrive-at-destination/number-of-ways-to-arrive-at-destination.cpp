class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
     vector<long long> way(n,0);
     vector<long long> dist(n,LLONG_MAX);
     priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;//dist,node;
     vector<vector<pair<long long,long long>>> arr(n);
     for(auto it:roads){
        arr[it[1]].push_back({it[0],it[2]});
        arr[it[0]].push_back({it[1],it[2]});
     }
     q.push({0,0}) ;
     dist[0]=0;
     way[0]=1;
     long long modulo=(1e9)+7;
     while(!q.empty()){
        long long length=q.top().first;
        long long node=q.top().second;
        q.pop();
        for(auto it:arr[node]){
            if(length+it.second<dist[it.first]){
                way[it.first]=way[node];
                dist[it.first]=(length+it.second);
                q.push({length+it.second,it.first});
            }
            else if(length+it.second==dist[it.first]){
                way[it.first]=(way[it.first]+way[node])%modulo;
            }
        }
     }
     return (way[n-1])%modulo;
    }
};