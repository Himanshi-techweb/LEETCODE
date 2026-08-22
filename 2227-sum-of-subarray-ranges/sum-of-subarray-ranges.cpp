class Solution {
public:
    int n;
    const int MOD =1e9+7;
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
    
    vector<int>  nge(vector<int>&arr){
        stack<int> st;
        vector<int> nsearr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            nsearr[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nsearr;
    }
    vector<int> pge(vector<int>&arr){
        stack<int> st;
        vector<int> psearr(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            psearr[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return psearr;
    }
    long long subArrayRanges(vector<int>& nums) {
        n=nums.size();
        vector<int> ngearr=nge(nums);
        vector<int> nsearr=nse(nums);
        auto psearr=pse(nums);
        auto pgearr=pge(nums);
         

        // vector<int> nsearr=nse(arr);
        // vector<int> psearr=pse(arr);
        long long mini=0LL;
        for(int i=0;i<n;i++){
           long long left=i-psearr[i];
           long long right=nsearr[i]-i;
           long long freq=(left*right);
           mini=(mini+(freq*nums[i]));

        }
        long long maxi=0LL;
        for(int i=0;i<n;i++){
           long long left=i-pgearr[i];
           long long right=ngearr[i]-i;
           long long freq=(left*right);
           maxi=(maxi+(freq*nums[i]));

        }
        long long ans=(maxi-mini);
        return ans;
    }
};