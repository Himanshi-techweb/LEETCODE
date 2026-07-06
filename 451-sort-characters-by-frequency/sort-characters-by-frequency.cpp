class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int> st;
       for(auto it:s){
        st[it]++;
       }
       priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> q;
       for(auto it:st){
           q.push({it.second,it.first});
       }
       string ans="";
       while(!q.empty()){
        auto front=q.top();
        q.pop();
        for(int i=0;i<front.first;i++){
            ans+=front.second;
        }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};