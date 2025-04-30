class Solution {
public:
    bool check(int i){
        int r=0;
        while(i>0){
            r++;
            i=i/10;
        }
        return r%2==0;
    }
    int findNumbers(vector<int>& arr) {
        int ans=0;
       for(auto x:arr){
        if(check(x))ans++;
       } 
       return ans;
    }
};