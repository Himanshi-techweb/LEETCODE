class node{
    public:
  int d;int r;int c;
  node(int d,int r,int c){
    this->d=d;
    this->r=r;
    this->c=c;
  }
};
class compare{
    public:
    bool operator()(node *a,node *b){
        return a->d>b->d;
    }
};
class Solution {
public:
   
    vector<int> smallestRange(vector<vector<int>>& arr) {
      priority_queue<node*,vector<node*>,compare> q; 
      int mini=INT_MAX;int maxi=INT_MIN;
      for(int i=0;i<arr.size();i++){
        mini=min(mini,arr[i][0]);maxi=max(arr[i][0],maxi);
        q.push(new node(arr[i][0],i,0));
      } int x=maxi;int y=mini;
      while(!q.empty()){
        auto front=q.top();q.pop();
        mini=front->d;int row=front->r;int col=front->c;
        if(maxi-mini<x-y){
            x=maxi;
            y=mini;
        }
        if(col+1<arr[row].size()){
            maxi=max(maxi,arr[row][col+1]);
            q.push(new node(arr[row][col+1],row,col+1));
        }
        else{
            break;
        }
      }
      vector<int> ans;
      ans.push_back(y);
      ans.push_back(x);
      return ans;
    }
};