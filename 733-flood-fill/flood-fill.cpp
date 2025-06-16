class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
     int row=arr.size();int col=arr[0].size();
     vector<vector<int>> visit(row,vector<int> (col,0));
     vector<vector<int>> copy=arr;
     stack<pair<int,int>>st;
     vector<vector<int>> rc={{-1,0},{0,1},{0,-1},{1,0}};
     if(arr[sr][sc]==color)return arr;
     int color2=arr[sr][sc];
     if(arr[sr][sc]!=color){
            st.push({sr,sc});
            //visit[sr][sc]=1;
            arr[sr][sc]=color;
     }
     while(!st.empty()){
        pair<int,int> front=st.top();
        st.pop();
        for(int i=0;i<4;i++){
        int nr=front.first+rc[i][0];
        int nc=front.second+rc[i][1];
        if(nr>=0 && nr<row && nc>=0 && nc<col && visit[nr][nc]==0 && arr[nr][nc]==color2){
            visit[nr][nc]=1;
            arr[nr][nc]=color;
            st.push({nr,nc});
        }
        }
     }
     return arr;
    }
};