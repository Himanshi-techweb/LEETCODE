class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int row=mat.size();int col=mat[0].size();
        int top=0;int down=row-1;int left=0;int right=col-1;
        vector<int> ans;
        while(left<=right && top<=down){
            for(int j=left;j<=right;j++){
                ans.push_back(mat[top][j]);
            }
            top++;
            for(int i=top;i<=down;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=down){
                for(int j=right;j>=left;j--){
                  ans.push_back(mat[down][j]);
                }
                
            }down--;
            if(left<=right){
                for(int i=down;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }    
            }left++;
        }
        return ans;
    }
};