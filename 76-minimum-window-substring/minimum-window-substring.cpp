class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> check;
       for(auto x:t){
        check[x]++;
       } int l=0;
       int r=0;
       int count=0;
       int s_index=0;
       int min_len=INT_MAX;
       while(r<s.length() ){
            if(check[s[r]]>0){
                count++;
            }
            check[s[r]]--;
            r++;
            while(count==t.size()){
               if((r-l)<min_len){
                min_len=r-l;
                s_index=l;
                }
                check[s[l]]++;
                if(check[s[l]]>0)count--;    
                l++;
            }
            
       }
       if(min_len==INT_MAX){
        return "";
       }
       string ans =s.substr(s_index,min_len);
       return ans;
    }
};