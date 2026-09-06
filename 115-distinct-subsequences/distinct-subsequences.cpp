class Solution {
public:
    vector<vector<int>> st;
    int solve(int i,int j,string &s ,string &t){
        if(j>=t.size())return 1;
        if(i>=s.size())return 0;
        if(st[i][j]!=-1)return st[i][j];
        int ans=0;
        //match
        if(s[i]==t[j]){
            ans+=solve(i+1,j+1,s,t);
                
        }
        //notmatch
        ans+=solve(i+1,j,s,t);
        return st[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        st.resize(s.size(),vector<int>(t.size(),-1));
        return solve(0,0,s,t);

    }
};