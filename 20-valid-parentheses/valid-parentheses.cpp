class Solution {
public:
    bool isValid(string s) {
    //   if(s.length==0)return true;
      stack<char> check;
      int i=0;
      while( i<s.length()){
         if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            check.push(s[i]);
         }
         else{
            if(check.empty())return false;
            char x=check.top();
            if((x=='(' && s[i]==')') || (x=='{' && s[i]=='}') || (x=='[' && s[i]==']')){
              check.pop();
            }
            else{
                return false;
            }
         }
         i++;
         }
         return check.empty();
      }
      
      
};