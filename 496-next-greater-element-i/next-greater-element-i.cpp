class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        stack<int> st;
        unordered_map<int,int> check;
        vector<int> ans(arr1.size(),-1);
       for(int i=arr2.size()-1;i>=0;i--){
         int x=-1;
         while(!st.empty() && st.top()<arr2[i]){
            st.pop();
         }  
         if(!st.empty() && st.top()>arr2[i]){
            x=st.top();
         }
         st.push(arr2[i]);
         check[arr2[i]]=x; 
       }
       for(int i=0;i<arr1.size();i++){
        if(check.find(arr1[i])!=check.end()){
            ans[i]=check[arr1[i]];
        }
       }
       return ans;
    }
};