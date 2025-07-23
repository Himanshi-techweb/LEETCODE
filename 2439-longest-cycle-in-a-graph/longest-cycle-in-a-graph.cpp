class Solution {
public:
     int ans=-1;
     ;
     void dfs(int i,vector<int> &edge,vector<int> &visit,vector<int> &pathvisit,vector<int> &count){
        if(i!=-1){
            visit[i]=1;pathvisit[i]=1;
            int j=edge[i];

            if(j!=-1 && !visit[j]){
                count[j]=(1+count[i]);
                dfs(j,edge,visit,pathvisit,count);
            }
            else if(j!=-1 && pathvisit[j]){
                ans=max(ans,count[i]-count[j]+1);
            }
            pathvisit[i]=0;
        }
        
     }
    int longestCycle(vector<int>& edge) {
        vector<int> count;
        count.resize(edge.size(),1);
        vector<int> visit(edge.size(),0);
        vector<int> pathvisit(edge.size(),0);
        for(int i=0;i<edge.size();i++){
            if(!visit[i]){
                dfs(i,edge,visit,pathvisit,count);
            }
        }
        return ans;
    }
};