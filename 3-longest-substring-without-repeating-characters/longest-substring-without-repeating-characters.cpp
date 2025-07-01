class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int l=0;int r=0;
      unordered_map<char,int> check;
      int cnt=0;int maxcnt=0;
      while(l<=r  && r<s.length()){
        check[s[r]]++;
        while(check[s[r]]>1){
            check[s[l]]--;
            l++;
        }
        cnt=(r-l+1);
        maxcnt=max(maxcnt,cnt);
        r++;
      } 
      return maxcnt; 
    }
};