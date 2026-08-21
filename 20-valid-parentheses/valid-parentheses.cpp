class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(!st.empty( ) && st.top()=='('  && ch==')')st.pop();
            else if(!st.empty() && st.top()=='[' && ch==']')st.pop();
            else if(!st.empty() && st.top()=='{' && ch=='}')st.pop();
            else st.push(ch);
        }
        return st.empty();
    }
};