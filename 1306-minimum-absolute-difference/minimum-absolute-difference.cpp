class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int mini=INT_MAX;
       for(int i=0;i+1<arr.size();i++){
        if(abs(arr[i]-arr[i+1])<mini){
            mini=abs(arr[i]-arr[i+1]);
        }
       }
       vector<vector<int>> ans;
       for(int i=0;i+1<arr.size();i++){
         if(abs(arr[i+1]-arr[i])==mini){
            ans.push_back({arr[i],arr[i+1]});
         }
       } 
       return ans;
    }
};