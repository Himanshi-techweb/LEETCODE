class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<char,int> check;
      unordered_map<char,int> require;
      for(auto it:t)require[it]++;
      int l=0;int r=0;int cnt=0;int len=INT_MAX;int s_i=-1;
      int curr=0;
      while(l<=r && r<s.size()){
        //check for each character if it is in check map
        check[s[r]]++;
        if(require.count(s[r]) && check[s[r]]==require[s[r]])curr++;
        while(curr==require.size()){
            if(r-l+1<len){
                len=r-l+1;s_i=l;
            }
            check[s[l]]--;
            if(require.count(s[l]) && check[s[l]]<require[s[l]])curr--;
            l++;
        }
        r++;
      } 
      if(len==INT_MAX)return "";
      return s.substr(s_i,len); 
    }
};