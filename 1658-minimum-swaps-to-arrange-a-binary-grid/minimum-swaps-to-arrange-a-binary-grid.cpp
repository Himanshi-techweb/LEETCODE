class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //if all column from 1 to n-1 are same'

        // unordered_map<int,int> rowcount;
        vector<int> rowcount(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            int count=0;
            for(int j=grid[0].size()-1;j>=0;j--){
               if(grid[i][j]==0)count++;
               else break; 
            }
            rowcount[i]=count;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int x=grid[0].size()-i-1;
            if(rowcount[i]>=x)continue;
            int k=i+1;
            while(k<grid.size() && rowcount[k]<x)k++;
            if(k==grid.size())return -1;
            ans+=(k-i);
            while(k>i){
               swap(rowcount[k],rowcount[k-1]);
               k--;
            }
        }
        return ans; 
    }
};