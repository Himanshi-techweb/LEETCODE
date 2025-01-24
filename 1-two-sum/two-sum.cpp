class Solution {
public:
// ans.push_back(check[temp]);
            // ans.push_back(i);
            //   for(int i=0;i<arr.size();i++){
    //       check[arr[i]]=i;
    //   }
    vector<int> twoSum(vector<int>& arr, int target) {
      unordered_map<int,int> check;
      for(int i=0;i<arr.size();i++){
        if(check.find(target-arr[i])!=check.end() && check[target-arr[i]]!=i){
            
            return {check[target-arr[i]],i};
        }
        check.insert({arr[i],i});
      }
      return {};
    }
};