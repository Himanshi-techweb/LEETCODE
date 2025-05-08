class Solution {
public:
    // int minTimeToReach(vector<vector<int>>& moveTime) {
        
    // }
    struct node{
     int r,c,time,cost;
    //  node(int r,int c,int time){
    //    r(r), c(c), time(time) {}
    //  }
    node(int r, int c, int time,int cost) : r(r), c(c), time(time),cost(cost) {}
    };
    struct comparator{
        bool operator()(node x1,node x2){
           return x1.time> x2.time;
        }
    };
    bool isvalid(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n)return true;
        return false;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
      int m=moveTime.size();
      int n=moveTime[0].size();
      vector<int> arr;
      arr={-1,0,1,0,-1};
      priority_queue<node ,vector<node> ,comparator> check;
      check.push(node(0,0,0,1));
      vector<vector<int>> mintime(m,vector<int> (n,INT_MAX));
      mintime[0][0]=0;
      while(!check.empty()){
        node front=check.top();
        check.pop();
        if(front.r==m-1 && front.c==n-1){return front.time;}
        for(int i=0;i<arr.size()-1;i++){
            int newr=(front.r)+arr[i];
            int newc=(front.c)+arr[i+1];
            if(isvalid(newr,newc,m,n) ){
                int change=max(front.time,moveTime[newr][newc]);
                if(change<mintime[newr][newc]){
                int cost=front.cost;
                int nextcost =(cost==1)?2:1;
                check.push(node(newr, newc, change+cost,nextcost));
                mintime[newr][newc]=change; }
            }
        } 
    }return 0;
    }
};