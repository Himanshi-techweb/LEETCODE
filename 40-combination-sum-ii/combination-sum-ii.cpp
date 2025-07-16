class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int tar,vector<int> &arr,vector<int> &a){
        if(tar==0){
            ans.push_back(a);
            return ;
        }
        if(i>=arr.size())return;
        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1])continue;
            if(arr[j]>tar)break;
            if(arr[j]<=tar){
                a.push_back(arr[j]);
                solve(j+1,tar-arr[j],arr,a);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> a;
       sort(candidates.begin(),candidates.end());
       solve(0,target,candidates,a);
       return ans; 
    }
};