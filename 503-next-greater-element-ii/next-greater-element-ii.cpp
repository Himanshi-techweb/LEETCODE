class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums[nums.size()-1];
        //for n-1th element
        for(int i=nums.size()-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])st.pop();
            st.push(nums[i]);
            
        }
        cout<<st.size()<<endl;
        int i=nums.size()-1;
        vector<int> ans(i+1);
        while(i>=0){
            int x=nums[i];
            while(!st.empty() && st.top()<=x)st.pop();
            ans[i]=(st.empty())?-1:st.top();
            st.push(nums[i]);
            i--;
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    //stack
    //   3 2
};