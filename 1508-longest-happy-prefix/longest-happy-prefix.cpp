class Solution {
public:
    string longestPrefix(string s) {
    //    unordered_set<string> prefix;
    //    string pre="";
    //    for(int i=0;i<s.length()-1;i++){
    //      pre+=s[i];
    //     //  prefix[pre]=true;
    //     prefix.insert(pre);
    //    } 
    //    unordered_set<string> suffix;
    //    string suf="";
    //    for(int i=s.length()-1;i>0;i--){
    //      suf=s[i]+suf;
    //     //  suffix[suf]=true;
    //     suffix.insert(suf);
    //    } 
    //    int max_len=0;
    //    string ans="";
    //    for(auto x:suffix){
    //     if( prefix.find(x)!=prefix.end() ){
    //         if(x.length()>max_len){
    //             ans=x;
    //             max_len=x.length();
    //         }
    //     }
    //    }
    //    return ans;
    // string ans="";
    // long long max_len=0;
    // for(int i=1;i<s.length();i++){
    //     if(s.substr(0,i)==s.substr(s.length()-i,i)){
    //         max_len=i;
            
    //     }
    // }return s.substr(0,max_len);
     
    int n=s.length();
    int len=0;
    vector<int> lps(n,0);
     for(int i=1,len=0;i<n;){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
          if(len!=0){
            len=lps[len-1];
          }
          else{
            lps[i]=0;
            i++;
          }
        }
     }
     len=lps[n-1];
     return s.substr(0,len);
    }
};