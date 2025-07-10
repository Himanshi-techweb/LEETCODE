class Solution {
public:
    // vector<int> nextgreater(vector<int> &arr){
    //     stack<pair<int,int>> st;
    //     vector<int> ans(arr.size(),-1);
    //     for(int i=0;i<arr.size();i++){
    //         while(!st.empty() && st.top().first<arr[i]){
    //             auto it=st.top();st.pop();
    //             ans[it.second]=arr[i];
    //         }
    //         st.push({arr[i],i});
    //     }
    //     return ans;
    // }
    // vector<int> previousgreater(vector<int> &arr){
    //     stack<pair<int,int>> st;
    //     vector<int> ans(arr.size(),-1);
    //     for(int i=arr.size()-1;i>=0;i--){
    //         while(!st.empty() && st.top().first<arr[i]){
    //           auto it=st.top();st.pop();
    //           ans[it.second]=arr[i];  
    //         }
    //         st.push({arr[i],i});
    //     }
    //     return ans;
    // }
    int trap(vector<int>& arr) {
    //    vector<int> ng=nextgreater(arr);
    //    vector<int> pg=previousgreater(arr);
       vector<int> leftMax(arr.size(),-1);
       vector<int> rightMax(arr.size(),-1);
       leftMax[0] = arr[0];
       for (int i = 1; i < arr.size(); i++)
        leftMax[i] = max(leftMax[i - 1], arr[i]);

       rightMax[arr.size() - 1] = arr[arr.size() - 1];
       for (int i = arr.size() - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], arr[i]);

       int cnt=0;
       for(int i=0;i<arr.size();i++){
        if(rightMax[i]!=-1 && leftMax[i]!=-1){
            cnt+=(min(rightMax[i],leftMax[i])-arr[i]);
        }
       }
       return cnt;
    }
};