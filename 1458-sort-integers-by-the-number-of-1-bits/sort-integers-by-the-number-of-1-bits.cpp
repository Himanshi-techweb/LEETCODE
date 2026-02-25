class Solution {
public:
    // unordered_map<int,int> check;
    vector<pair<int,int>> x;
    static bool sort_func(pair<int,int> a,pair<int,int>b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
      int i= __builtin_popcount(5) ;
      for(int i=0;i<arr.size();i++){
        x.push_back({arr[i],__builtin_popcount(arr[i])});
      }
      sort(x.begin(),x.end(),sort_func);
      vector<int> ans;
      for(auto it:x){
        ans.push_back(it.first);
      }
      return ans;
    }
};