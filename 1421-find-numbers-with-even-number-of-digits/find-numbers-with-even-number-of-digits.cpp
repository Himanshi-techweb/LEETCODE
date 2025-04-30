class Solution {
public:
    bool check(int i){
        return ((int)log10(i)+1)%2==0;
    }
    int findNumbers(vector<int>& arr) {
        int ans=0;
       for(auto x:arr){
        if(check(x))ans++;
       } 
       return ans;
    }
};