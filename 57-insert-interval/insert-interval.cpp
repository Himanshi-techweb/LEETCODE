class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {     bool check =false;
      for(int i=0;i<intervals.size();i++){
        if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                check=true;
                break;
            }
        }
        if(!check)intervals.push_back(newInterval); 
      vector<vector<int>> ans;
      ans.push_back(intervals[0]);
      for(int i=0;i<intervals.size();i++){
        vector<int> &temp=ans.back();
        if(temp[1]>=intervals[i][0]){
            temp[1]=max(intervals[i][1],temp[1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
      }
      return ans; 
    }
};