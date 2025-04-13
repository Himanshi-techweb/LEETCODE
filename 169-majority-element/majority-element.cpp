class Solution {
public:
    int majorityElement(vector<int>& arr) {
       int count=0;int tar=0;
       for(auto x:arr){
        if(count==0){
            tar=x;
            count++;
        }
        else{
            count+=((tar==x)?1:-1);
        }
       }
       //here it is guarantee that it exist otherwise run and chec that count of tar is greater than n/2 there then return that number;
       return tar;
    }
};