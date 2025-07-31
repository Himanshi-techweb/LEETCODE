class Solution {
public:
    vector<int> addrow(int i){
        int row=i;
        int col=i+1;
        vector<int> ans(col,1);
        ans[0]=1;
        for(int j=1;j<col;j++){
            ans[j]=ans[j-1]*(row-j+1)/j;
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;
       ans.push_back({1});
       for(int i=1;i<numRows;i++){
        vector<int> check=addrow(i);
        ans.push_back(check);
       } 
       return ans;
    }
};