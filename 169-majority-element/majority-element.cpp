class Solution {
public:
    int majorityElement(vector<int>& arr) {
     unordered_map<int,int> check;
     for(auto x:arr){
        check[x]++;
     }
     int n=arr.size();
     n=n/2;
     for(auto x:check){
        if(x.second>n)return x.first;
     }   return 0;
    }
};