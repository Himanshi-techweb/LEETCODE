class Solution {
public:
    vector<int> bfs(int start,vector<int> &adj){
        int n=adj.size();
        vector<int> ans;
        queue<int> q;
        q.push(start);
        vector<int> visit(n,0);
        vector<int> dist(n,-1);
        dist[start]=0;
        visit[start]=1;
        while(!q.empty()){
            auto front=q.front();q.pop();
            if(adj[front]!=-1 && !visit[adj[front]]){
                q.push(adj[front]);
                dist[adj[front]]=dist[front]+1;
                visit[adj[front]]=1;
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& adj, int node1, int node2) {
        int n=adj.size();
        vector<int> arr1=bfs(node1,adj);
        vector<int> arr2=bfs(node2,adj);
        int mini=INT_MAX;int ans=-1;
        for(int i=0;i<n;i++){
            int x=INT_MIN;
            if(arr1[i]!=-1 && arr2[i]!=-1 ){
              int maxDist=max(arr1[i],arr2[i]);
              if(maxDist<mini){
                mini=maxDist;ans=i;
              }
            }
        }
        return ans;
    }
};