class Solution {
public:
    int check(string s){
      if(s.size()==0)return 0;
      stack<char> st;
      for(int i=0;i<s.size();i++){
        if(s[i]=='(')st.push(s[i]);
        else if(!st.empty() && st.top()=='(' && s[i]==')')st.pop();
        else if(s[i]==')')st.push(s[i]);
      }
      return st.size();
    }
    void solve(string s,vector<string> &ans,int mini,unordered_set<string>&store){
        if(mini==0){
          if(check(s)==0){
            ans.push_back(s);
          }
          return;
        }
        for(int i=0;i<s.size();i++){
            auto left=s.substr(0,i);
            auto right=s.substr(i+1,s.size());
            if(store.find(left+right)==store.end()){
              store.insert(left+right);
              solve(left+right,ans,mini-1,store);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
       vector<string> ans;
       unordered_set<string> store;
       solve(s,ans,check(s),store);
       return ans; 
    }
};