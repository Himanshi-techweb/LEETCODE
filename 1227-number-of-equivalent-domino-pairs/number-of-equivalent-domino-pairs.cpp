class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoe) {
       vector<int> check(100,0);int ans=0;
       for(auto i:dominoe){
        int x=min(i[0],i[1]);
        int y=max(i[0],i[1]);
        int z=(x*10)+y;
        ans+=(check[z]);
        check[z]++;
       }
       return ans;
    }
};