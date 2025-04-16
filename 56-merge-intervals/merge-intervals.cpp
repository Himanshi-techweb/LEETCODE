class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
       sort(arr.begin(),arr.end());
       vector<vector<int>>ans;
       vector<int> curr=arr[0];
       for(int i=1;i<arr.size();i++){
          vector<int> next=arr[i];
          if(curr[1]>=next[0]){
            curr[1]=max(curr[1],next[1]);
          }
          else{
            ans.push_back(curr);
            curr=next;
          }
       }
       ans.push_back(curr);
       return ans; 
    }
};