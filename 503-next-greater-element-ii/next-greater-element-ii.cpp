class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
       for(int i=0;i<arr.size();i++) {
           for(int j=i;j<i+arr.size();j++){
            if(arr[j%arr.size()]>arr[i]){
                ans[i]=arr[j%arr.size()];
                break;
            }
           } 
       }
       return ans;
    }
};