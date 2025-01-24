class Solution {
public:
    string common(string a,string b){
        int x=min(a.length(),b.length());
        string ans="";
        int i=0;
        while(i<x){
            if(a[i]==b[i]){
                ans+=a[i];
            }
            else{
                break;
            }
            i++;
        }return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
      string x;
      stack<string> check;
      for(auto x:strs){
          check.push(x);
      } 
      while(check.size()!=1){
        string temp1=check.top();
        check.pop();
        string temp2=check.top();
        check.pop();
        string ans=common(temp1,temp2);
        if(ans=="")return "";
        check.push(ans);
      }
      return check.top();
    }
};