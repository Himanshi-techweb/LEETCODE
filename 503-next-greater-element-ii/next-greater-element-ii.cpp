class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
        int n=arr.size();
        arr.insert(arr.end(),arr.begin(),arr.end());
       stack<pair<int,int>> st;
       for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top().first<arr[i%arr.size()] ){
            ans[st.top().second]=arr[i%arr.size()];
            st.pop();
        }
        if(i<n)st.push({arr[i],i});
       }
       return ans;
    }
};