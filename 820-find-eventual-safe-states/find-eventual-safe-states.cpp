class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> in(n,0);
        vector<vector<int>> revadj(n);
        for(auto i=0;i<graph.size();i++){
            vector<int> arr=graph[i];
            for(auto it:arr){
                
                revadj[it].push_back(i);
                in[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        // vector<int> ans;
        

        while(!q.empty()){
            auto front=q.front();
            ans.push_back(front);
            q.pop();
            for(auto it:revadj[front]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        

    }
};