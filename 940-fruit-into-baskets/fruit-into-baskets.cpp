class Solution {
public:
    int totalFruit(vector<int>& arr) {
      unordered_map<int,int> check;
      int l=0;int r=0;int maxcnt=0;
      while(l<=r && r<arr.size()){
        check[arr[r]]++;
        while(check.size()>2){
            check[arr[l]]--;
            if(check[arr[l]]==0){
                check.erase(arr[l]);
            }
            l++;
        }
        maxcnt=max(maxcnt,r-l+1);
        r++;
      }
      return maxcnt;
    }
};