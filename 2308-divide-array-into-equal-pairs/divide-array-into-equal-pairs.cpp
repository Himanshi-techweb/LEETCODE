class Solution {
public:
    bool divideArray(vector<int>& nums) {
       map<int,int> check;
       for(auto x:nums){
        check[x]++;
       }
       for(auto &x: check){
         if(x.second %2!=0)return false;
       } 
       return true;
    }
};