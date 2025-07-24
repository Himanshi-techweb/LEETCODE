class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        queue<int> q;
        vector<vector<int>> freq(n,vector<int> (26,0));
        int ans=-1;
        int count_0degree=0;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }

        //fill queue from indegree
        //fill freq of color corroesponding to node have indegree 0 in graph
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
                freq[i][colors[i]-'a']++;
                ans=max(ans,freq[i][colors[i]-'a']);
            }
        }
        //iterate through queue for further indegree
        while(!q.empty()){
            auto u=q.front();q.pop();
            count_0degree++;
            int color_u=colors[u]-'a';
            for(auto v:adj[u]){
                int color_v=colors[v]-'a';
                for(int i=0;i<26;i++){
                   int check=freq[u][i];
                   if(color_v==i)check+=1;
                   freq[v][i]=max(freq[v][i],check);
                   ans=max(ans,freq[v][i]);
               }
               in[v]--;
               if(in[v]==0)q.push(v);
            }
        }
        if(count_0degree!=n)return -1;
        return ans;
    }
};