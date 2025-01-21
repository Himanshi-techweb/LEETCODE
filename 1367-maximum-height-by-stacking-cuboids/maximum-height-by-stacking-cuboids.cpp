
class Solution {
public:
    bool check(vector<int> &a,vector<int>&b){
        if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2] )return true;
        else return false;
    }
    int solveTab(vector<vector<int>> arr,int n){
        vector<int> currrow(n+1,0);
        vector<int> nextrow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
         for(int prev=curr-1;prev>=-1;prev--){
            int include=0;
            if(prev==-1 || check(arr[curr],arr[prev])){
                include=arr[curr][2]+nextrow[curr+1];
            }
            int exclude=nextrow[prev+1];
            currrow[prev+1]=max(include,exclude);
         }
         nextrow=currrow;
        }
        return nextrow[0];
    }
    int maxHeight(vector<vector<int>>& arr) {
      for(auto & vec:arr){
        sort(vec.begin(),vec.end());
      } 
      sort(arr.begin(),arr.end()); 
      int n=arr.size();
      return solveTab(arr,n);
      
      
    }
};