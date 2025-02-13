class Solution {
public:
    bool canFinish(int x, vector<vector<int>>& arr) {
       if(arr.size()==0)return true;
       queue<int> q;
       vector<vector<int>> check(x);
       for(int i=0;i<arr.size();i++){
            check[arr[i][1]].push_back(arr[i][0]);
       }
       vector<int> in(x,0);
       for(int i=0;i<x;i++){
        for(auto it:check[i]){
            in[it]++;
        }
       } 
       for(int i=0;i<x;i++){
        if(in[i]==0)q.push(i);
       }
       vector<int> ans;
       while(!q.empty()){
         int j=q.front();
         ans.push_back(j);
         q.pop();
         for(auto it:check[j]){
            in[it]--;
            if(in[it]==0)q.push(it);
         }
         
       }
       return x==ans.size();
    }
};