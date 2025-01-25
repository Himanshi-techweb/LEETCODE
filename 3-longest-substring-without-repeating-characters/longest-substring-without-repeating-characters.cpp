class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int l=0;int r=0;int max_l=0;int max_f=0;
      unordered_map<char,int> check;
       while(r<s.length()){
          check[s[r]]++;
          while(check[s[r]]>1){
            check[s[l]]--;
            l++;
          }
           max_l=max(max_l,r-l+1);
          r++;
       }
       return max_l;
    }
};