class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0)return 0;
       unordered_set<int> st;
       int ans=1;int cnt=0;
       for(auto it:arr){
        st.insert(it);
       }
       for(auto it:st){
         if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            ans=max(ans,cnt);
         }
         
       }
       return ans;
    }
};