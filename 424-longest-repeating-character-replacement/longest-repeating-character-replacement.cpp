class Solution {
public:
    int characterReplacement(string s, int k) {
      int l=0;int r=0;int maxf=0;int maxlen=0;
      unordered_map<char,int> check;
      while(l<=r && r<s.size()){
        check[s[r]]++;
        maxf=max(maxf,check[s[r]]);
        if((r-l+1)-maxf>k){
            check[s[l]]--;
            l++;
        }
        else{
            maxlen=max(maxlen,r-l+1);
        }
        r++;
      }
      return maxlen;
    }
};