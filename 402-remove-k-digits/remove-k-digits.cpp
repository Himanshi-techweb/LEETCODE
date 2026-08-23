class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string ans;
        for(int i=0;i<num.size();i++){
            int n=num[i]-'0';
            while(!st.empty() && st.top()>n && k>0){
                st.pop();k--;
            }
            
            st.push(n);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            int n=st.top();
            char ch=n+'0';
            ans+=ch;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int start=0;
        while(start<ans.size() && ans[start]=='0')start++;
        ans=ans.substr(start);
        return ans.empty()?"0":ans;
    }
};