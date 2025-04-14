class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
       unordered_map<int,int> check;int n=arr.size();
       vector<int> ans;
       for(auto x:arr){
          check[x]++;
       }
       for(auto x:check){
        if(x.second>n/3){
            ans.push_back(x.first);
        }
       }
       return ans; 
    }
};