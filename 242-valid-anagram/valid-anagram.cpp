class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length()!=t.length())return false;
      unordered_map<char,int> check;
      for(int i=0;i<s.length();i++){
        check[s[i]]++;
      } 
      for(int i=0;i<t.length();i++){
        char temp=t[i];
        if(check.find(temp)!=check.end()){
            check[temp]--;
        }
        else{
            return false;
        }
      } 
      for(auto x:check){
        if(x.second>0)return false;
      }
      return true;
    }
};