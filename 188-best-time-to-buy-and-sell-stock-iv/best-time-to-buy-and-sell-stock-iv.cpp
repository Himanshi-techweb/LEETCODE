class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        int n=price.size();
       vector<vector<int>> next(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int j=0;j<k;j++){
                    int profit=0;
                    if(buy){
                        profit=max(-price[i]+next[0][j],0+next[1][j]);
                    }
                    else{
                        if(j<k)profit=max(price[i]+next[1][j+1],0+next[0][j]);
                        else profit=next[0][j];
                    }
                    curr[buy][j]=profit; 
                }
            }next=curr;
        }
        return next[1][0]; 
    }
};