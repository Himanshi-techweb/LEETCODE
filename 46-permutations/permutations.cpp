class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &arr){
        if(i==arr.size()-1){
           ans.push_back(arr);
           return ;
        }
        
        for(int j=i;j<arr.size();j++){
            swap(arr[i],arr[j]);
            solve(i+1,arr);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        solve(0,arr);
        return ans;
    }
};