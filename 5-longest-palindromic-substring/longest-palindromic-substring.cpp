class Solution {
public:
    string longestPalindrome(string s) {
       int x=s.length();
       int max_len=0;
       string ans;
            auto check=[&](int l,int r){
               while(l>=0 && r<x && s[l]==s[r]){
              if(r-l+1>max_len){
                max_len=max(max_len,r-l+1);
                ans=s.substr(l,max_len);  
              }
              l--;
              r++;
              } 
            }; 
            for(int i=0;i<x;i++){
                check(i,i);
                check(i,i+1);
            }return ans;
        }
};