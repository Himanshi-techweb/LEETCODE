class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> lastindex(26,-1);
       for(int i=0;i<s.size();i++){
        lastindex[s[i]-'a']=i;
       }
       string result=""; 
       vector<bool> visit(26,false);
       for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(visit[ch-'a'])continue;
        while(result.size()>0 && result.back()> ch && lastindex[result.back()-'a']>i){
            visit[result.back()-'a']=false;
            result.pop_back();
        }
        result+=ch;
        visit[ch-'a']=true;
       }
       return result;
    }
};