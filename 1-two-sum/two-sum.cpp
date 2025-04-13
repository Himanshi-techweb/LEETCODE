class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
      unordered_map<int,int> check;vector<int> ans(2,-1);
    //   for(int i=0;i<arr.size();i++){
    //     check[arr[i]]=i;
    //   }
      for(int i=0;i<arr.size();i++){
        int tar2=tar-arr[i];
        if(check.find(tar2)!=check.end() && i!=check[tar2]){
          ans[0]=i;
          ans[1]=check[tar2];
        }
        check[arr[i]]=i;
      } return ans; 
    }
};