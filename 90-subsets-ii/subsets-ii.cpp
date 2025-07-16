class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void solve(int i,vector<int> &arr,vector<int> &a){
        if(i==arr.size()){
            st.insert(a);return;
        }
        for(int j=i;j<arr.size();j++){
           if(j>i && arr[j]==arr[j-1])continue;
            solve(j+1,arr,a); 
           a.push_back(arr[j]);
           solve(j+1,arr,a);
           a.pop_back();
           
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      vector<int> a;
      solve(0,arr,a);
      for(auto it:st)ans.push_back(it);
      return ans;
    }
};