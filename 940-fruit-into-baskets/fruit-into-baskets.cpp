class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int,int> check;
      int len=0;
      int l=0;int r=0;
      while(l<=r && r<fruits.size()){
        check[fruits[r]]++;
        while(check.size()>2){
            check[fruits[l]]--;
            if(check[fruits[l]]==0)check.erase(fruits[l]);
            l++;
        }
            len=max(len,r-l+1);
            r++;
      } 
      return len; 
    }
};