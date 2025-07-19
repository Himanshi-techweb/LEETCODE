class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int tar,vector<int> &arr,vector<int> &a){
        if(i>=arr.size())return;
        if(tar==0){
          ans.push_back(a);
          return;
        }
        //taken
        if(arr[i]<=tar){
          a.push_back(arr[i]);
          solve(i,tar-arr[i],arr,a);
          a.pop_back();
        }
        solve(i+1,tar,arr,a);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> a;
        solve(0,target,candidates,a);
        return ans;
    }
};