class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    //    ordered_map<int,int> check;//store number in submatrix + count;
       int m=grid.size();int n=grid[0].size();
       vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));
       if(k>m || k>n)return ans;

       
    //    for(int i=0;i<k;i++){
    //       for(int j=0;j<k;j++){
    //         check[grid[i][j]]++;
    //       }
    //    } 
       

    //    int j=0;int i=0;
    //    while(i+k-1<m){
    //     int st_row=i;
    //     while(j+k-1<n){ 
    //         int st_col=j;
    //         //include next column assume k-1 column in back map it
    //         int end_col=j+k-1;
    //         for(int it=st_row;it<i+k;it++){
    //             check[grid[it][end_col]]++;
    //         }
            
    //         //iterate through map
    //         int prev=INT_MAX;
    //         int mini=INT_MAX;
    //         for(auto it:check){
    //             if(prev==INT_MAX){
    //                 prev=it;
    //             }
    //             else{
    //                 mini=min(min,abs(prev-it));
    //                 prev=it; 
    //             }
    //         }
    //         ans[st_row][st_col]=mini;

    //         //remove previous col 
    //         j++;
    //     }
    //    }




       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //now take submatrix of i+k and j+k
            map<int,int> check;
            int mini=INT_MAX;
            int prev=INT_MAX;
            if(i+k-1<m && j+k-1<n){
                for(int row=i;row<=i+k-1;row++){
                    for(int col=j;col<=j+k-1;col++){
                        check[grid[row][col]]++;
                    }
                }
                if(check.size()==1){
                    ans[i][j]=0;
                }else{
                    for(auto it:check){
                        if(prev==INT_MAX){
                            prev=it.first;
                        }
                        else{
                            mini=min(mini,abs(prev-it.first));
                            prev=it.first; 
                        }
                    }
                    ans[i][j]=(mini==INT_MAX)?0:mini;
                }
            }    
        }
       }
       return ans;
    }
};