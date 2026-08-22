class Solution {
public:
    int n;
    vector<int>  nse(vector<int>&arr){
        stack<int> st;
        vector<int> nsearr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            nsearr[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nsearr;
    }
    vector<int> pse(vector<int>&arr){
        stack<int> st;
        vector<int> psearr(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            psearr[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return psearr;
    }
    const int MOD=1e9 +7;
    int sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        vector<int> nsearr=nse(arr);
        vector<int> psearr=pse(arr);
        long long ans=0LL;
        for(int i=0;i<n;i++){
           long long left=i-psearr[i];
           long long right=nsearr[i]-i;
           long long freq=(left*right)%MOD;
           ans=(ans+(freq*arr[i])%MOD)%MOD;

        }
        return ans%MOD;
    }
};