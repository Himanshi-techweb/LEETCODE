class Solution {
public:
    int n;
    vector<int>  nge(vector<int>&arr){
        stack<int> st;
        vector<int> nsearr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            nsearr[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nsearr;
    }
    vector<int> pge(vector<int>&arr){
        stack<int> st;
        vector<int> psearr(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            psearr[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return psearr;
    }
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        auto ngearr=nge(heights);
        auto pgearr=pge(heights);
        int ans=0;
        for(int i=0;i<n;i++){
            int l=pgearr[i];
            int r=ngearr[i];
            ans=max(ans,(r-l-1)*heights[i]);
        }
        return ans;
    }
};