class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
       vector<int> visit(n,0);
       queue<int> q;
       q.push(0);
       while(!q.empty()){
        auto front=q.front();
        q.pop();
        if(visit[front])continue;
        visit[front]=1;
        for(auto it:rooms[front]){
            if(!visit[it]){
                q.push(it);
            }
        }
       }
       for(auto it:visit)if(it==0)return false;
       return true; 
    }
};