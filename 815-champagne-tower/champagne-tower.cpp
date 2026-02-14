class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //in each row(i) there must be col from 1 to row (i)
        //check for (i,j) number of glass on it
        // if number of glass is greater than 
        vector<vector<double>> check(query_row+1,vector<double>(query_row+1,0.0));
        if(poured==1){
            if(query_row==0 && query_glass==0)return 1;
            return 0;
        }
        check[0][0]=(poured);
        double left=0.0;
        double right=0.0;
        for(int i=1;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    check[i][0]=max(0.0,(check[i-1][0]-1)/2.0);
                }
                else if(j==query_row){
                    check[i][query_row]=max(0.0,(check[i-1][query_row-1]-1)/2.0);
                }
                else{
                    left=max(0.0,(check[i-1][j-1]-1)/2.0);
                    right=max(0.0,(check[i-1][j]-1)/2.0);
                    check[i][j]=left+right;
                }
            }
        }
       return min(1.0,check[query_row][query_glass]); 
    }
};