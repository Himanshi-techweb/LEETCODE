class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
            }
        }int check=arr[0]%x;
        sort(arr.begin(),arr.end());
        for(auto i:arr){
            if(i%x!=check)return -1;
        }int n=arr.size();int ans=INT_MAX;int q=0;
        if(n%2!=0){
            int k=arr[n/2];
            for(auto i:arr){
                q+=abs((i-k))/x;
            }
            ans=min(ans,q);
        }
        else{
            int l=arr[0];
            int r=arr[1];
            if(n==2){
              l=arr[0];
              r=arr[1];
            }
            else{
                l=arr[n/2];
                r=arr[(n/2)+1];
            }
                while(l<=r){
                  q=0;
                  int k=l;
                  for(auto i:arr){
                  q+=abs((i-k))/x;
                } 
                ans=min(ans,q); 
                l=l+x;
            }
        }
        return ans;
    }
};