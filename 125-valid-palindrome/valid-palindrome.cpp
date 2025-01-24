class Solution {
public:
    bool palindrome(string x){
        int n=x.length();
        int i=0;
        int j=n-1;
        while(i<j){
          if(x[i]!=x[j])return false;  
          i++;
          j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
      string check="";
      for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z')   || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            check+=tolower(s[i]);
        } 
      }  
      return palindrome(check);
    }
};