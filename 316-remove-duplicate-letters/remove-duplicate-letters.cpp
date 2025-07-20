class Solution {
public:
    string removeDuplicateLetters(string s) {
       unordered_map<char,int> check;
       unordered_set<char> use;
       for(auto it:s)check[it]++;
       string ans="";
       for(int i=0;i<s.size();i++){
        check[s[i]]--;
        if(use.count(s[i]))continue;
        while(ans.size() && ans.back()>s[i] && check[ans.back()]>0){
           use.erase(ans.back());
           ans.pop_back();
        }
        ans+=s[i];
        
        use.insert(s[i]);
       }
       return ans;
    }
};