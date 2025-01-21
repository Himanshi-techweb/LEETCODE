class Solution {
public:
    int solve(vector<int> &arr){
        int n=arr.size();
        if(n==0)return 0;
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>ans.back())ans.push_back(arr[i]);
            else{
                int index =lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
      sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
      });
    //   for(int i=0;i<arr.size()-1;i++){
    //    if(arr[i][0]==arr[i+1][0] && arr[i][1]<arr[i+1][1]){
    //     swap(arr[i],arr[i+1]);
    //    }
    //   } 
      vector<int> check;
      for(auto vec:arr){
        check.push_back(vec[1]);
      }
      return solve(check); 
    }
};