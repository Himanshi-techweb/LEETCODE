class Solution {
public:
    void rotate(vector<int>& arr, int k) {
       int n=k%arr.size();
       n=arr.size()-n;
       vector<int> ans;
       for(int i=n;i<arr.size();i++){
         ans.push_back(arr[i]);
       } 
       for(int i=0;i<n;i++){
        ans.push_back(arr[i]);
       }
       for(int i=0;i<ans.size();i++){
        arr[i]=ans[i];
       }
    }
};