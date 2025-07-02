class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
       unordered_set<int> st;int cnt=0;int maxcnt=0;
       for(auto it:arr){
         st.insert(it);
       } 
       for(int i=0;i<arr.size();i++){
         if(st.find(arr[i]-1)==st.end()){
            cnt=0;int check=arr[i];
            while(st.find(check)!=st.end()){
               cnt++;
               st.erase(check);
               check=check+1;
            }
            maxcnt=max(maxcnt,cnt);
         }
       }
       return maxcnt;
    }
};