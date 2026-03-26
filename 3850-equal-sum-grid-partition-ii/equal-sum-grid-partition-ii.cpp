class Solution {
public:
    bool check_row(vector<vector<int>> &grid,unsigned long long total,int m,int n){
        //top to bottom horizontally
        unordered_set<unsigned long long> st;
        unsigned long long sum=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                st.insert(grid[i][j]);
                if(j==n-1){
                    unsigned long long bottom=total-sum;
                    if(bottom==sum){cout<<"row";return true;}
                    if(n==1 && st.find(sum-bottom)!=st.end() && (grid[0][0]==sum-bottom || grid[i][0]==sum-bottom)){cout<<"row1";return true;  }             
                    if(i==0 && st.find(sum-bottom)!=st.end() && (grid[0][0]==sum-bottom || grid[0][n-1]==sum-bottom)){cout<<"row2";return true;}
                    if( n>1 && i!=0 && st.find(sum-bottom)!=st.end() ){cout<<"row3";return true;}
                }
            }
        }
        return false;
    }
    bool check_col(vector<vector<int>> &grid,unsigned long long total,int m,int n){
        unsigned long long sum=0;
        unordered_set<int> st;
        for(int j=0;j<n-1;j++){
            for(int i=0;i<m;i++){
                sum+=grid[i][j];
                st.insert(grid[i][j]);
                if(i==m-1){
                unsigned long long right=total-sum;
                cout<<sum<<" "<<right<<endl;
                if(sum==right){return true;}
                if(m==1 && st.find(sum-right)!=st.end() && (grid[0][0]==sum-right || grid[0][j]==sum-right)){cout<<"col1";return true;}
                if(j==0 && st.find(sum-right)!=st.end() && (grid[0][0]==sum-right  || grid[m-1][0]==sum-right)){cout<<"col2";return true;}
                if(m>1 && j!=0 && st.find(sum-right)!=st.end()){cout<<"col3";return true;}
                }
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        unsigned long long total=0;
        cout<<m<<" "<<n<<endl;
        vector<vector<int>> reverse(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                reverse[m-1-i][j]=grid[i][j];
                total+=grid[i][j];
            }
        }
        if(check_row(grid,total,m,n) || check_row(reverse,total,m,n))return true;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                reverse[i][n-1-j]=grid[i][j];
            }
        }
        if(check_col(grid,total,m,n) || check_col(reverse,total,m,n))return true;
        return false;
    }
};