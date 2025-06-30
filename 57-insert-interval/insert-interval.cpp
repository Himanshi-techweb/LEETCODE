class Solution {
public:
    // void insertinterval()
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& ni) {
        vector<vector<int>> ans;
        int i=0;
        while(i<arr.size() && arr[i][1]<ni[0]){
            ans.push_back(arr[i]);
            i++;
        }
        while(i<arr.size() && arr[i][0]<=ni[1]){
            ni[0]=min(arr[i][0],ni[0]);
            ni[1]=max(arr[i][1],ni[1]);
            i++;
        }
        ans.push_back(ni);
        while(i<arr.size() ){
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};