class Solution {
public:
    int numRabbits(vector<int>& arr) {
       unordered_map<int,int> check;int ans=0;
       for(auto x:arr){
         check[x]++;
         if(check[x]==x+1){
            ans+=(x+1);
            check[x]=0;
         }
       }
       for(auto [x,freq] :check){
         if(freq!=0){
            ans+=(x+1);
         }
       }
       return ans;
    }
};