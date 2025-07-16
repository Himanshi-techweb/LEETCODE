class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int i,vector<int> &arr,vector<int> &a){
        if(i==arr.size()){
            st.insert(a);return;
        }
           solve(i+1,arr,a); 
           a.push_back(arr[i]);
           solve(i+1,arr,a);
           a.pop_back();
           
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      vector<int> a;
      solve(0,arr,a);
      for(auto it:st)ans.push_back(it);
      return ans;
    }
};