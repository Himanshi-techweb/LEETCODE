class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            cost[it[0]][it[1]]=it[2];
            cost[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)cost[i][i]=0;
        for(int t=0;t<n;t++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && cost[i][t]!=INT_MAX && cost[t][j]!=INT_MAX)cost[i][j]=min(cost[i][j],cost[i][t]+cost[t][j]);
                }
            }
        }
        vector<int> cnt(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && cost[i][j]<=distanceThreshold)cnt[i]++;
            }
        }
        int mini=INT_MAX;int i=0;
        for(int k=0;k<n;k++){
            if(mini>=cnt[k]){
                mini=cnt[k];
                i=k;
            }
        }
        return i;
    }
};