class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      vector<int> ans;
      int i=0;
      unordered_map<int,int> check;
      for(int i=0;i<arr.size();i++){
          check[arr[i]]=i;
      }
      for(int i=0;i<arr.size();i++){
        int temp=target-arr[i];
        if(check.find(temp)!=check.end() && check[temp]!=i){
            ans.push_back(check[temp]);
            ans.push_back(i);
            break;
        }
        
      }
      return ans;
    }
};