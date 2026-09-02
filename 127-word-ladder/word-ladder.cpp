class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string > st;
        for(auto it:wordList){
            st.insert(it);
        }
        if(st.find(endWord)==st.end())return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto front=q.front();
            auto str=front.first;
            auto cnt=front.second;
            if(str==endWord)return cnt;
            
            q.pop();
            for(int i=0;i<str.size();i++){
                char ori=str[i];
                for(auto k=0;k<26;k++){
                    str[i]=k+'a';
                    if(st.find(str)!=st.end()){
                        q.push({str,cnt+1});
                        st.erase(str);
                    }
                }
                str[i]=ori;
            }
        }
        return 0;
    }
};