class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int cnt=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        vector<int> x;
        cout<<"1"<<endl;
        //leftcolumn
        int j=0;
        for(int i=0;i<m;i++){
            x.clear();
            int r=i;int c=j;
            while(r>=0&& c<n){
                x.push_back(matrix[r][c]);
                r--;c++;
            }
            cout<<"x"<<endl;
            if(cnt%2!=0)reverse(x.begin(),x.end());
            ans.insert(ans.end(),x.begin(),x.end());
            cnt++;

        }
        cout<<"2"<<endl;
        //bottom row
        int i=m-1;
        for(int j=1;j<n;j++){
            x.clear();
            int r=i;int c=j;
            while(r>=0 && c<n){
                x.push_back(matrix[r][c]);
                r--;c++;
            }
            if(cnt%2!=0)reverse(x.begin(),x.end());
            ans.insert(ans.end(),x.begin(),x.end());
            cnt++;
        }
        return ans;
    }
};