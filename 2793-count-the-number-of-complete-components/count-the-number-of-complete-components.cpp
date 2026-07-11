class Solution {
public:
    pair<int,int> dfs(int i,vector<vector<int>>&adj,vector<int>&visit){
        visit[i]=true;
        int cntedge=0;int cntnode=1;
        for(auto it:adj[i]){
            cntedge++;
            if(!visit[it]){
                auto x=dfs(it,adj,visit);
                cntedge+=x.first;
                cntnode+=x.second;
            }
        }
        
        return {cntedge,cntnode};
    }
    //0->1
    //1->0,2
    //2->1
    //0 se 1 then cntedge=1 and cntnode=1

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visit(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                pair<int,int> count=dfs(i,adj,visit);
                int countedge=count.first;
                int countnode=count.second;
                // cout<<i<<" "<<countedge<<" "<<countnode<<endl;
                if(countnode==1)ans++;
                else if(countnode==2 && countedge==2)ans++;
                else if(countedge>=(countnode*countnode)-countnode)ans++;
            }
        }
        return ans;
    }
};