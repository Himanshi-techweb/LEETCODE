class Solution {
public:
    void dfs(string s,unordered_set<string> &check){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                if(check.count(s)){
                    check.erase(s);
                    dfs(s,check);
                }
                swap(s[i],s[j]);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> check;
        queue<string> q;int cnt=0;
        for(auto it:strs)check.insert(it);
        while(check.size()>0){
            string s=*check.begin();
            check.erase(s);
            cnt++;
            dfs(s,check);
        }
        return cnt;
    }
};