class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int k=0;
        int m=mat.size();int n=mat[0].size();
        while(k<4){
            vector<vector<int>> rot(n,vector<int>(n));
            int count=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    rot[j][n-i-1]=mat[i][j];
                    cout<<rot[j][n-i-1]<<" ";
                    if(target[j][n-i-1]==rot[j][n-i-1])count++;

                    
                }
                cout<<endl;
            }
            cout<<count<<endl;
            cout<<endl;
            if(count==(n*n))return true;
             
            //check
            // bool flag=true;
            // for(int  i=0;i<m;i++){
            //     for(int j=0;j<n;j++){
            //         if(target[i][j]!=rot[i][j]){
            //             flag=false;
            //             break;
            //         }
            //     }
            // }
            // if(flag)return true;
            // cout<<"rotate"<<endl;
            k++;
            mat=rot;
        }
        return false;
    }
};