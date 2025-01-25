class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> check;
      for(auto x:strs){
        // int vec[26]={0};note that it cannot serve as key fro unordered_map as raw array does not have hash function and equality comparator
        // vector<int> vec(26,0);
        string vec(26,'0');
        for(auto c:x){
          vec[c-'a']++;
        }
        check[vec].push_back(x);
      } 
      vector<vector<string>> ans;
      for(auto x:check){
        ans.push_back(x.second);
      }
      return ans;
    }
};