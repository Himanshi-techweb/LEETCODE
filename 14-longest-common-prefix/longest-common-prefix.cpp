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
    string longestCommonPrefix(vector<string>& str) {
    //   string x;
    //   stack<string> check;
    //   for(auto x:strs){
    //       check.push(x);
    //   } 
    //   while(check.size()!=1){
    //     string temp1=check.top();
    //     check.pop();
    //     string temp2=check.top();
    //     check.pop();
    //     string ans=common(temp1,temp2);
    //     if(ans=="")return "";
    //     check.push(ans);
    //   }
    //   return check.top();
    string prefix=str[0];
    for(int i=1;i<str.size();i++){
        int j=0;
        while(j<prefix.length() && j<str[i].length() && prefix[j]==str[i][j]){
            j++;
        }
        prefix=prefix.substr(0,j);
        if(prefix=="")return "";
    }
    return prefix;
    }
};