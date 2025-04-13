class Solution {
public:
    int majorityElement(vector<int>& arr) {
       map<int,int> check;int n=arr.size();
       for(auto x:arr){
        check[x]++;
        if(check[x]>n/2){
            return x;
        }
       } return 0;
    }
};