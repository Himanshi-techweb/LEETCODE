class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       unordered_set<int> st;int cnt=0;int maxcnt=0;
       for(auto it:arr){
         st.insert(it);
       } 
       for(auto it:st){
         if(!st.count(it-1)){
            cnt=1;int check=it;
            while(st.count(check+1)){
               cnt++;
               check=check+1;
            }
            maxcnt=max(maxcnt,cnt);
         }
       }
       return maxcnt;
    }
};