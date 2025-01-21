class compare{
  public:
  bool operator()(vector<int>&a,vector<int> &b){
    if(a[0]==b[0])return a[1]>b[1];
    else return a[0]<b[0];
  }
};
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
    //   sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>&b){
    //     if(a[0]==b[0]) return a[1]>b[1];
    //     else return a[0]<b[0];
    //   });
    sort(arr.begin(),arr.end(),compare());
    //   for(int i=0;i<arr.size()-1;i++){
    //    if(arr[i][0]==arr[i+1][0] && arr[i][1]<arr[i+1][1]){
    //     swap(arr[i],arr[i+1]);
    //    }
    //   } wrong
      vector<int> check;
      for(auto vec:arr){
        check.push_back(vec[1]);
      }
      if(arr.size()==0)return 0;
        vector<int>ans;
        ans.push_back(check[0]);
        for(int i=1;i<check.size();i++){
            if(check[i]>ans.back())ans.push_back(check[i]);
            else{
                int index =lower_bound(ans.begin(),ans.end(),check[i])-ans.begin();
                ans[index]=check[i];
            }
        }
        return ans.size();
    }
};