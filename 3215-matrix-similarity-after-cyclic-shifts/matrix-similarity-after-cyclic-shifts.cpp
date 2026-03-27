class Solution {
public:
    void left(vector<int>&arr,int k){
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
    }
    void right(vector<int>& arr,int k){
        reverse(arr.begin(),arr.end());
        int actual=arr.size()-k;
        reverse(arr.begin(),arr.begin()+actual);
        reverse(arr.begin()+actual,arr.end());
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        k=k%n;int count=0;
        vector<vector<int>> arr=mat;
        for(int i=0;i<m;i++){
            if(i%2==0)left(arr[i],k);
            else right(arr[i],k);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=arr[i][j])return false;
            }
        }
        return true;
        
    }
};