// class Solution {
// public:
//     vector<int> (int numCourses, vector<vector<int>>& prerequisites) {
        
//     }
// };
class Solution {
public:
    // vector<int> findOrder(int x, vector<vector<int>>& arr) {
    // }  
    vector<int> findOrder(int V, vector<vector<int>> &edge) {
       vector<vector<int>>arr(V);
       vector<int> in(V,0);
       queue<int>q;
       vector<int>topo;
       for(int i=0;i<edge.size();i++){
        arr[edge[i][0]].push_back(edge[i][1]);
        in[edge[i][1]]++;
       }
       for(int i=0;i<V;i++){
           if(in[i]==0)q.push(i);
       }
       while(!q.empty()){
           int front=q.front();q.pop();
           topo.push_back(front);
           for(auto it:arr[front]){
               in[it]--;
               if(in[it]==0)q.push(it);
           }
       }
       for(auto it:in){
           if(it>0)return {};
       }
       reverse(topo.begin(),topo.end());
       return topo;
    }
};