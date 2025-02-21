class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;
        vector<int> distance(n,INT_MAX);
        
        vector<int> stop(n,0);
        distance[src]=0;
         q.push({0,src,0});//[stop,node,distance]
         vector<vector<vector<int>>> adj(n);
         for(auto &it: flights){
            adj[it[0]].push_back({it[1],it[2]});
         }
         while(!q.empty()){
            int stop_count=q.front()[0];
            int node=q.front()[1];
            int dist=q.front()[2];
            q.pop();
            if(stop_count>k )continue;
            // if( node==dst){
            //     distance[dst]=min(distance[dst],dist);
            // }
            // else{
                for(auto it:adj[node]){
                  if(dist+it[1]<distance[it[0]]){
                    distance[it[0]]=dist+it[1];
                    q.push({stop_count+1,it[0],dist+it[1]});
                  }
                }
            // }
            }
        if(distance[dst]==INT_MAX)return -1;
         return distance[dst];
    }
};