class Solution {
public:
    vector<vector<int>> rc={{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& arr) {
        int m=arr.size();int n=arr[0].size();
        int rotten =0;int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==2){
                    rotten++;
                    q.push({i,j});
                }
                if(arr[i][j]==1)fresh++;
            }
        }
        if(fresh==0)return 0;
        int cnt=0;
        while(!q.empty()){
            bool flag=false;
            int size=q.size();
            for(int i=0;i<size;i++){
            auto front=q.front();
            q.pop();
            int r=front.first;
            int c=front.second;
            for(int i=0;i<4;i++){
                int nr=r+rc[i][0];int nc=c+rc[i][1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && arr[nr][nc]==1){
                    fresh--;  
                    cout<<nr<<" "<<nc<<"another  ";
                    q.push({nr,nc});
                    arr[nr][nc]=2;
                    flag=true;
                }
            }
            
            }
            if(flag)cnt++;
        }
        
        if(fresh==0)return cnt;
        
        return -1;
    }
};