class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      vector<vector<int>> arr(n+1) ; 
      for(auto it:dislikes){
           arr[it[0]].push_back(it[1]);
           arr[it[1]].push_back(it[0]);
      }
       vector<int> color(n+1,-1);
       for(int i=1;i<n+1;i++){
        if(color[i]==-1){
          queue<int> q;
           q.push(i);
           color[i]=0;
           while(!q.empty()){
         int node=q.front();
         q.pop();
         for(auto i:arr[node]){
            if(color[i]==-1){
                color[i]=!color[node];
                q.push(i);
            }
            else if(color[i]==color[node]){
                return false;
            }
         }
       }
        }
       }
       return true;
    }
};