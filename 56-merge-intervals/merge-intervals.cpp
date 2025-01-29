class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     if(intervals.size()==0)return {};
     if(intervals.size()==1)return intervals;
      stack<vector<int>> q;
      sort(intervals.begin(),intervals.end());
      for(int i=intervals.size()-1;i>=0;i--){
        q.push(intervals[i]);
      }
      vector<vector<int>> ans;
      while(q.size()>1){
        vector<int> temp1=q.top();
        q.pop();
        vector<int> temp2=q.top();
        if(temp2[0]<=temp1[1]){
           temp1[1]=max(temp1[1],temp2[1]);
           q.pop();
           q.push(temp1);
        }
        else{
            ans.push_back(temp1);
        } 
      }
      ans.push_back(q.top());
      return ans;
      
    }
};